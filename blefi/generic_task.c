//*****************************************************************************
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

//*****************************************************************************
//
// generic_task.c - Implementation of a generic time based task.
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup get_weather
//! @{
//
//*****************************************************************************
#include <hw_types.h>
#include <uart.h>
#include <datatypes.h>
#include <simplelink.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ti/sysbios/knl/Semaphore.h>
#include "osi.h"
#include "wifi_api.h"
#include "gateway_api.h"
#include "gateway_cmds.h"
#include "datatypes.h"
#include "database.h"
#define BLEFI_CFG_FILE "blefi.cfg"

blefiCfg_t blefiCfgRec;
void * blefiCfgData;
bool is_blefiCfgReady = false;
bool is_blefiCfgupdate = false;
OsiSyncObj_t g_GWGenSyncObj;

/* Net COnfig Sync Object */
OsiSyncObj_t g_NetStatSyncObj;

#define GENERIC_TASK_STACK_SIZE	2048
#define GENERIC_TASK_FREQ_MS 250
#define AUTO_SCAN_DEFAULT 0 //in secs
#define AUTO_SCAN_MAX_VALUE 300
#define AUTO_SCAN_MIN_VALUE 30
#define AUTO_CON_ENABLE 1
#define AUTO_CON_DISABLE 0


#define GW_KEY_LEN  		0x6
#define GW_RANDOM_KEY_LEN   0x6
#define MAC_ADDR_LEN	    0x6


typedef enum BleCurrState {
		BLE_SCANRESP,
		BLE_SCANCOMP,
		BLE_LINKESTABLISH,
		BLE_LINKTERMINATE,

		BLE_UNKOWN = 0x99,
}ebleCurrState;


extern uint8 current_state;
extern e_cmd_status lastCmdResponse;


extern unsigned short int lock_conn_handle;

extern unsigned short int uuid_1_handle;
extern uint8 uuid_1_handle_found;

extern unsigned short int uuid_2_handle;
extern uint8 uuid_2_handle_found;

extern unsigned short int uuid_3_handle;
extern uint8 uuid_3_handle_found;

extern unsigned short int uuid_4_handle;
extern uint8 uuid_4_handle_found;

extern unsigned short int uuid_5_handle;
extern uint8 uuid_5_handle_found;

extern unsigned short int uuid_noti_handle;
extern uint8 uuid_noti_handle_found;

extern device_db_t * DeviceRec[10];
unsigned char gw_wlan_mac[SL_MAC_ADDR_LEN] = {0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6};
unsigned char gwRandomKey[GW_RANDOM_KEY_LEN];

unsigned int cfgSize = 0;
unsigned int autoScanTimeout = 0;

static struct sockaddr_in 	sAddr;
static int 				iSockID;
									  //192.168.1.5	//54.71.27.65
unsigned long  		g_ulDestinationIP = 0xC0A80104; //0x36471B41;//0xC0A80105; // 0xc0a3D9Fa;//0xC0A82BD0; // 0xAC140A07; // 0xC0A82BD0; // 0xc0a3D9Fa;  // 192.168.217.250
unsigned int   		g_uiPortNum = 5683;

static uint8 is_KeepAliveAckRecv = 0;


static char randomKey[6];

static unsigned char talafe_bdAddr[B_ADDR_LEN];
static unsigned char talafe_DeviceIdx;
static short int talafe_uConnId;

ebleCurrState g_bleCurrState = BLE_UNKOWN;

OsiSyncObj_t g_GWUuidWSyncObj;

SlFdSet_t g_ReadFds;

typedef enum{
    // Choosing -0x7D0 to avoid overlap w/ host-driver's error codes
    SOCKET_CREATE_ERROR = -0x7D0,
    BIND_ERROR = SOCKET_CREATE_ERROR - 1,
    LISTEN_ERROR = BIND_ERROR -1,
    SOCKET_OPT_ERROR = LISTEN_ERROR -1,
    CONNECT_ERROR = SOCKET_OPT_ERROR -1,
    ACCEPT_ERROR = CONNECT_ERROR - 1,
    SEND_ERROR = ACCEPT_ERROR -1,
    RECV_ERROR = SEND_ERROR -1,
    SOCKET_CLOSE_ERROR = RECV_ERROR -1,
    DEVICE_NOT_IN_STATION_MODE = SOCKET_CLOSE_ERROR - 1,    
    DEVICE_START_FAILED = DEVICE_NOT_IN_STATION_MODE - 1,
    INVALID_HEX_STRING = DEVICE_START_FAILED - 1,
    TCP_RECV_ERROR = INVALID_HEX_STRING - 1,
    TCP_SEND_ERROR = TCP_RECV_ERROR - 1,
    FILE_NOT_FOUND_ERROR = TCP_SEND_ERROR - 1,
    INVALID_SERVER_RESPONSE = FILE_NOT_FOUND_ERROR - 1,
    FORMAT_NOT_SUPPORTED = INVALID_SERVER_RESPONSE - 1,
    FILE_OPEN_FAILED = FORMAT_NOT_SUPPORTED - 1,
    FILE_WRITE_ERROR = FILE_OPEN_FAILED - 1,
    INVALID_FILE = FILE_WRITE_ERROR - 1,
    SERVER_CONNECTION_FAILED = INVALID_FILE - 1,
    GET_HOST_IP_FAILED = SERVER_CONNECTION_FAILED  - 1,
	STATUS_CODE_MAX = -0xBB8,
}e_AppStatusCodes;


typedef enum{
    // Choosing -0x7D0 to avoid overlap w/ host-driver's error codes
    CONN_REQ_SEND = 51,
	SEND_DEVICE_STATUS,
	
	RESET_KEY = 0x02,
	GET_DEVICE_STATUS,
	//DEVICE_CONTROL,
	DEVICE_ON,
	DEVICE_OFF,
	ADD_KEY,
	DELETE_KEY,
	CHANGE_KEY,
	GET_KEY_DETAIL,
	KEEP_ALIVE_ACK = 99,
	DEVICE_CONTROL = 0x100,
}e_AppCmdCode;
/*
 * EXTERN FUNCTIONS
 * */
extern void Button2Init(void);
extern void Button2IntClear(void);
extern void Button2IntDisable(void);
extern void Button2IntEnable(void);

extern unsigned int getGenericTaskTicks(void);
extern void HandleError(unsigned char * filename, unsigned int line_num, unsigned char error);




extern void fillOtaMetaDefaultCfg(void * otaMeta);
extern int getSizeofOtaMeta();
extern void DB_FlushSyncObjects();

static int SendStatus_CMD2_4_5_6_7_8 (char cmdID, char* pkt, char* respMsg, unsigned int pktSize, unsigned int respMsgLen);
static int SendStatus_CMD3(char cmdID, char* pkt, char* respMsg, unsigned int pktSize, unsigned int respMsgLen);
static int SendStatus_CMD9(char cmdID, char* pkt, char* respMsg, unsigned int pktSize, unsigned int respMsgLen);


static void Process_cmd(char cmdID, char* pkt, unsigned int pktSize);
static void parseResponse(int len, char* buffer);

static e_cmd_status process_addkeys_cmd (char* pkt,  unsigned int pktSize);
static e_cmd_status process_delkeys_cmd (char* pkt,  unsigned int pktSize);
static e_cmd_status process_changekeys_cmd(char* pkt,  unsigned int pktSize);

short int t_scan_and_connect();

static e_cmd_status process_unlock_cmd (char* pkt,  unsigned int pktSize);
e_cmd_status process_lock_cmd (char* pkt,  unsigned int pktSize);


int ConnectToServer();
int Send_TCPKeepAlive();

void doHandleCmdtimeout();

OsiSyncObj_t g_GWConSyncObj;

/*
 *  FUNCTIONS
 * */

unsigned int getGenericTaskTicksPerSec()
{
	return(1000/GENERIC_TASK_FREQ_MS);
}

#define KEEP_ALIVE_PKT_LEN 		13
int Send_TCPKeepAlive()
{
	long lRetVal = -1;
	static char keepAlivePkt[KEEP_ALIVE_PKT_LEN];
	int i = 0;
	
	is_KeepAliveAckRecv = 0;
	
	keepAlivePkt[0] = ((KEEP_ALIVE_PKT_LEN & 0xFF00)>> 8) ;
	keepAlivePkt[1] = (KEEP_ALIVE_PKT_LEN & 0xFF);
	keepAlivePkt[2] = 99;
	//keepAlivePkt[3] = 01;					// Keep Alive SYN
	memcpy(keepAlivePkt+3 , "HUB-123456", 10);
	
	Report("\n\r");
//    for (i = 0; i < KEEP_ALIVE_PKT_LEN ; i++) {
//    	Report("{%d} ",keepAlivePkt[i]);
//    }
	Report("\n\r");
#if 0
	lRetVal = sl_Send(iSockID, keepAlivePkt, KEEP_ALIVE_PKT_LEN , 0 );
	if( lRetVal < 0 )
	{
		// error
		Report("\n\rERROR IN SEND KEEP ALIVE PACKET\n\r");
		sl_Close(iSockID);
		ASSERT_ON_ERROR(SEND_ERROR);
	}
#endif	
	Report("\n\r");
	memset(keepAlivePkt, 0, KEEP_ALIVE_PKT_LEN);
	return 0;
}

void doPeriodicScan()
{
	int devices_found;
	if (GC_IsBLEReady() != true)
	{
		return;
	}
	if(*(blefiCfgRec.autoScan) == 0)
	{
		if(autoScanTimeout!=0xFFFF)
		{
			/*
			 * This is the condition where the autoscan is zero
			 * and the trigger is not from interrupt
			 */

			return;
		}

	}
	//Button2IntDisable();
	autoScanTimeout++;
	if(autoScanTimeout>=(getGenericTaskTicksPerSec()* (*(blefiCfgRec.autoScan))))
	{
		devices_found = GC_Scan(GW_CALL_BLOCKING);
		if (devices_found < 0) {
			UART_PRINT("\n\r[GW] ERROR - Discovery already in progress");
		}
		autoScanTimeout = 0;
	}
	//Button2IntEnable();
}

void GW_DataCb(unsigned char DataType, ErrorFlag_t ErrorFlag,void* DataParams)
{
	Report("\n\r DataCB [%x]", DataType);
	
	gwData_t* pData = (gwData_t*)DataParams;
	unsigned char i ;

	 switch (DataType)
	 {
		 case GW_DATA_GET:
		 {
			 if(ErrorFlag == NO_ERROR)
			 {
				 UART_PRINT("\n\r");
				 UART_PRINT(" Device - %d ,value -  ",pData->getRsp.connhandle );
				 for(i=0; i<pData->getRsp.ValueLen ;i++)
				 {
					 UART_PRINT(" 0x%x", pData->getRsp.pValueBuffer[i]);
				 }
				 UART_PRINT("\n\r");
				 parseResponse(pData->getRsp.ValueLen, pData->getRsp.pValueBuffer);
			 }
			 else if (ErrorFlag == ERROR_INVALIDCONNHNDL)
			 {
				UART_PRINT("\n\rInvalid connection handle");
				UART_PRINT("\n\r");
			 }
			 else if (ErrorFlag == ERROR_INVALIDSTRING)
			 {
				UART_PRINT("\n\rInvalid character string");
				UART_PRINT("\n\r");
			 }
			 else
			 {
				UART_PRINT("\n\rERROR in executing GET ");
				UART_PRINT("\n\r");
			 }
		 }
		 break;

		 case GW_DATA_SET:
		 {
			if(ErrorFlag == NO_ERROR)
			{
				UART_PRINT("Device - %d ",pData->setRsp.connhandle);
				UART_PRINT("\n\r");
			//	Message(COMMAND_PROMPT);
			}
			else if (ErrorFlag == ERROR_INVALIDCONNHNDL)
			{
				UART_PRINT("\n\rInvalid connection handle");
				UART_PRINT("\n\r");
			//	Message(COMMAND_PROMPT);
			}
			else if (ErrorFlag == ERROR_INVALIDSTRING)
			{
				UART_PRINT("\n\rInvalid character string");
				UART_PRINT("\n\r");
			//	Message(COMMAND_PROMPT);
			}
			else
			{
				 UART_PRINT("\n\rERROR in executing SET ");
				 UART_PRINT("\n\r");
	        //     Message(COMMAND_PROMPT);
			}
		 }
		 break;

		 default:
			 break;
	 }
}

void GW_EventCb(unsigned char EventType, ErrorFlag_t ErrorFlag,void* EventParams)
{
	gwEvent_t* pEvent = (gwEvent_t*)EventParams;

	 switch (EventType)
	 {
		 case GW_EVENT_SCANRSP:
		 {
			UART_PRINT("\n\rDevice Scan Done ");
			talafe_DeviceIdx = pEvent->scanRsp.scanIdx;
			g_bleCurrState = BLE_SCANRESP; 
		 }
		 break;

		 case GW_EVENT_SCANCOMPLETE:
		 {
			UART_PRINT("\n\rDevice Establish Connection ");
			g_bleCurrState = BLE_SCANCOMP;
			/* Sending Connection Requset */
			
			//talafe_uConnId = GC_LinkEstablish(talafe_DeviceIdx , GW_CALL_BLOCKING , (unsigned char*)talafe_bdAddr );

		 }
		 break;

		 case GW_EVENT_LINKESTABLISH:
		 {
			g_bleCurrState = BLE_LINKESTABLISH;
			
			UART_PRINT("\n\r[GEN_TASK] Connected to Device - ");
			UART_PRINT("%d  %s %s",pEvent->linkEst.connhandle ,
								   pEvent->linkEst.deviceName ,
								   Util_convertBdAddr2Str(pEvent->linkEst.bdAddr));
			UART_PRINT("\n\r");
		 }
		 break;

		 case GW_EVENT_LINKTERMINATE:
		 {
			g_bleCurrState = BLE_LINKTERMINATE;
			
			UART_PRINT("\n\rDisconnected the Device - ");
			UART_PRINT("%d  %s %s reason- 0x%x",pEvent->linkTerm.connhandle ,
												pEvent->linkTerm.deviceName ,
												Util_convertBdAddr2Str(pEvent->linkTerm.bdAddr),
												pEvent->linkTerm.reason);
			UART_PRINT("\n\r");
		 }
		 break;

		 default:
			 break;
	 }
}

void fnPtrScanListAndConn(unsigned char devIndex, char * devName , unsigned char *bleAddr,unsigned char addrType)
{
	UART_PRINT("\n\r[GEN_TASK] %d     %s     %s      %d",devIndex ,devName, Util_convertBdAddr2Str(bleAddr), addrType);
	unsigned char bdAddr[B_ADDR_LEN];
	
	if ( strncmp(Util_convertBdAddr2Str(bleAddr), "0xB0B448BF1403", 14) == 0 )
	{
		Report("[GEN_TASK] Valied Device Found");
		if (g_bleCurrState == BLE_LINKESTABLISH)
			return;
		
		talafe_uConnId = GC_LinkEstablish(devIndex , GW_CALL_BLOCKING , (unsigned char*)bdAddr );
		if(talafe_uConnId >= 0)
		{
			UART_PRINT("\n\r[GEN_TASK] Device successfully connected , "
					"Conn Id - %d BD addr -%s\n\r",talafe_uConnId ,Util_convertBdAddr2Str(bdAddr));
		}
		else
		{
			UART_PRINT("\n\r[GEN_TASK] Device connection not successful");
		}
	}
}

short int t_scan_and_connect()
{
	int devices_found;
	// 1. Scan Lock Device
	// 2. Wait until Scan is not done, Use SCAN blocking calloc
	// 3. Check if we found any lock 
	// 4. Connect with lock
	UART_PRINT("\n\r[GEN_TASK] t_scan_and_connect [IN]");
	
	if (GC_IsBLEReady() != true)
	{
		return -1;
	}
	
	if (g_bleCurrState == BLE_LINKESTABLISH)
	{
		return -2;
	}
	
	/*1 & 2*/  
	devices_found = GC_Scan(GW_CALL_BLOCKING);
	
	UART_PRINT("\n\r[GEN_TASK] t_scan_and_connect > devices_found [%d]",devices_found);
	/*3*/ 
	if (devices_found)
	{
		/* COMP DEVICE ADDRESS IF VAILED */
		GC_DeviceScanList(fnPtrScanListAndConn);
		return 0;
	}
	UART_PRINT("\n\r[GEN_TASK] t_scan_and_connect [IN]");
	return -3;
}

static int InitSocket()
{
    long lRetVal = -1;


      /* Resolve HOST NAME/IP */
 //   lRetVal = sl_NetAppDnsGetHostByName((signed char *)"www.myindian.com",
 //                                         strlen((const char *)"www.myindian.com"),
 //                                         &g_ulDestinationIP,SL_AF_INET);
	  
	Report("IP from mDNS [%x]\n\r", g_ulDestinationIP);
	SL_FD_ZERO(&g_ReadFds);
//	if(lRetVal < 0)
	{
//	  ASSERT_ON_ERROR(GET_HOST_IP_FAILED);
	}

	/* Set up the input parameters for HTTP Connection */
	sAddr.sin_family = AF_INET;
	sAddr.sin_port = htons(5683);
	sAddr.sin_addr.s_addr = sl_Htonl(g_ulDestinationIP);

	return 1;
}

int ConnectToServer()
{
	int             iStatus = 0;
	int             iAddrSize;
	char			buffer[50] = "XXXHUB1234567";

	int i = 0;
	long lRetVal = -1;
	//struct SlTimeval_t tv, *p_tv;
	char len[2];
	char *rcvBuf;
	unsigned int bufLen = 0;
	
	iAddrSize = sizeof(SlSockAddrIn_t);

	// creating a TCP socket
	iSockID = sl_Socket(SL_AF_INET,SL_SOCK_STREAM, 0);
	if( iSockID < 0 )
	{
		Report("Connecting To Server... Socket Create Failed [%d] \n\r",iStatus);
		ASSERT_ON_ERROR(SOCKET_CREATE_ERROR);
	}
	

    // connecting to TCP server
    iStatus = sl_Connect(iSockID, ( SlSockAddr_t *)&sAddr, iAddrSize);
    if( iStatus < 0 )
    {
        // error
        Report("\n\r Connecting To Server... Failed Error [%d] \n\r",iStatus);
        sl_Close(iSockID);       
        ASSERT_ON_ERROR(CONNECT_ERROR);
    }
	Report("Connecting To Server... Success Sending Cmd\n\r");

	/* Set CMD ID */
	bufLen = strlen(buffer);
	buffer[0] = 0;//(( bufLen >> 8 ) && 0xFF );
	buffer[1] = ( bufLen );
	buffer[2] = CONN_REQ_SEND;
	
	Report("data len [%d] [%d] [%d]\n\r", bufLen, buffer[0], buffer[1]);
	

	iStatus = sl_Send(iSockID, buffer, bufLen , 0 );
    if( iStatus < 0 )
    {
        // error
        sl_Close(iSockID);
        ASSERT_ON_ERROR(SEND_ERROR);
    }

    lRetVal = sl_Recv(iSockID,len,sizeof(char)*2,0);
    if (lRetVal < 0 ) {
		sl_Close(iSockID);
    	Report("Read Data Error\n\r");
    	return -1;
	}
	else if (dataLen < 2)
	{
		sl_Close(iSockID);
    	Report("Read Data LEN >2 %d\n\r", bufLen);	
	}
	
	bufLen = len[0];
	bufLen = (bufLen << 8) | len[1];
	bufLen -= 2;
	
    Report("Data to be Read [%d] [%d] [%d] [%d]", len[0], len[1], lRetVal, bufLen);
	
	rcvBuf = (char *)malloc(sizeof(char) * bufLen);
	
	lRetVal = sl_Recv(iSockID,rcvBuf,(sizeof(char)*bufLen),0);
    if (lRetVal < 0) {
    	Report("Read Data Error\n\r");
		free(rcvBuf);
    	return -1;
	}	
	
	Report("\n\r RCV-->[%d]\n\r",lRetVal);
    for (i = 0; i < bufLen ; i++) {
    	Report("{%c:%x} ",rcvBuf[i],rcvBuf[i]);
    }
	
	osi_SyncObjSignal(&g_GWConSyncObj);
    Report("\n\r");
	free(rcvBuf);

    return 0;
}


//****************************************************************************
//
//! Task function implementing the GW generic  functions
//!
//! \param none
//!
//! \return None.
//
//****************************************************************************
struct Packet {
	int 	len;
	char 	cmdId;
	char* 	data;
};

void GwKeepAliveTask(void *pvParameters)
{
	volatile unsigned char LoopVar = 0xFF;
	static int timeout = 0;
	is_KeepAliveAckRecv = 1;
	
	while (LoopVar)
	{
		Report("\n\r Waiting for Connection to be Estb");
		osi_SyncObjWait(&g_GWConSyncObj,OSI_WAIT_FOREVER); //Wait until the Connetionn with Server is ON.
		
		while (LoopVar) {
			osi_Sleep(GENERIC_TASK_FREQ_MS);
			timeout++;
			
			if (timeout == 20) {
				if (!is_KeepAliveAckRecv) {
					Report("\r Keep Alive SYN Timeout\n\r");
					//sl_Close(iSockID); 
					timeout = 0;
					break;
				}
				timeout = 0;
				Send_TCPKeepAlive();
			}
		}
	}	
}

void GwGenericTask(void *pvParameters)
{
    volatile unsigned char LoopVar = 0xFF;
	
	/***************
	  Pkt Data var
	****************/
	long lRetVal = -1;
	char pktLen[2];
	char pktCmdID = 0x0;
	char *pkt;
	unsigned int dataLen = 0, i = 0;
	
	//struct Packet pkt;
	
    osi_SyncObjWait(&g_NetStatSyncObj,OSI_WAIT_FOREVER); //Wait until the network is ON.
 
	Report("\r Connecting To Server \n\r");
	ConnectToServer();
	Report("Connected To Server Scanning Now\n\r");
    //GC_Scan(GW_CALL_BLOCKING);
	Report("Scanning DONE\n\r");
	while (LoopVar) 
	{
		osi_SyncObjWait(&g_GWConSyncObj,OSI_WAIT_FOREVER); //Wait until the Connetionn with Server is ON.
		
		while(LoopVar)
		{
			static int timeout = 0;
			
			dataLen = 0x0;
			pktLen[0] = 0x0;
			pktLen[1] = 0x0;
			Report("\n\rWaiting for Packet\n\r");
			
			osi_Sleep(GENERIC_TASK_FREQ_MS);
			
		#if 0
			timeout++;
			
			if (timeout == 20) {
				if (!is_KeepAliveAckRecv) {
					Report("\r Keep Alive SYN Timeout\n\r");
					sl_Close(iSockID); 
					timeout = 0;
					break;
				}
				timeout = 0;
				Send_TCPKeepAlive();
			}
		#endif
		
			lRetVal = sl_Recv(iSockID,pktLen,sizeof(char)*2,0);
			if (lRetVal < 0) {
				Report("Read Data Error\n\r");
				sl_Close(iSockID); 
				break;
			}
			
			if(lRetVal < 2)
				continue;
			
			dataLen = pktLen[0];
			dataLen = (dataLen << 8) | pktLen[1];
			if (dataLen)
				dataLen -= 2;
			else {
				Report("Invalid data length \n\r");
				sl_Close(iSockID); 
				break;
			}
			Report("Data to be Read [%d] [%d]\n\r", dataLen, pktLen[1]);

			pkt = (char *)malloc(sizeof(char) * dataLen);
			if (!pkt) {
				Report("Malloc failed\n\r");
				sl_Close(iSockID);       
				break;
			}
			lRetVal = sl_Recv(iSockID,pkt,(sizeof(char)*dataLen),0);
			if (lRetVal < 0) {
				Report("Read Data Error\n\r");
				sl_Close(iSockID);  
				free(pkt);
				break;
			}	
			pktCmdID = pkt[0];
			Process_cmd(pktCmdID, pkt+1, dataLen);
			free(pkt);
		}
	}
}

static void parseResponse(int len, char* buffer)
{
	switch(buffer[0]) {
		case AUTH_MASTER_KEY:
		Report("\n\r AUTH_MASTER_KEY... Random key");
		if (buffer[1] == 0x01) {
			memcpy(gwRandomKey, buffer+2, GW_RANDOM_KEY_LEN);
			current_state |= (DEV_NOTI_DONE | RANDOM_KEY_SET);
		} else if(buffer[1] == 0x02) {
			current_state &= ~(RANDOM_KEY_SET);
		}
		break;
		
		case AUTH_MASTER_R_KEY:
		Report("\n\r AUTH_MASTER_KEY... Random key");
		if (buffer[1] == 0x01) {
			memcpy(gwRandomKey, buffer+2, GW_RANDOM_KEY_LEN);
			current_state |= (DEV_NOTI_DONE | RANDOM_KEY_SET);
		} else if(buffer[1] == 0x02) {
			current_state &= ~(RANDOM_KEY_SET);
		}
		
		break;
		case ADD_GUEST:
		
		break;
		case DEL_GUEST:
		
		break;
		case CHANGE_GUEST_INFO:
		
		break;
		case CHANGE_MASTER_KEY:
		
		break;
		case AUTO_LOCK_SETTING:
		
		break;
		case CHANGE_VOL_LEVEL:
		
		break;
		case UNLOCK:
		Report("\n\r Unlock Response");
		if (buffer[1] == 0x01) {
			Report("\n\r Success");
			lastCmdResponse = CMD_EXE_SUCCESS;
			osi_SyncObjSignal(&g_GWUuidWSyncObj);
			
		} else if(buffer[1] == 0x02) {
			Report("\n\r Failed");
			lastCmdResponse = CMD_EXE_FAILED;
			osi_SyncObjSignal(&g_GWUuidWSyncObj);
		}
			
		break;
		case LOCK:
		Report("\n\r Lock Response");
		if (buffer[1] == 0x01) {
			Report("\n\r Success");
			lastCmdResponse = CMD_EXE_SUCCESS;
		}
		break;
		case CURRENT_STATUS_ADMIN:
		
		break;
		case CURRENT_STATUD_GUEST:
		
		break;
		
		default:
		
		break;
	}
}

static void Process_cmd(char cmdID, char* pkt, unsigned int pktSize)
{
	char respBuf[25];
	unsigned int respBufLen = 0 ;
	e_cmd_status status = CMD_ERROR;
	
	switch(cmdID) {
		case RESET_KEY:
			Report("\r RESET KEY\n\r");
			
			respBufLen = snprintf(respBuf, 25, "KEY RESET SUCCESS ");
			SendStatus_CMD2_4_5_6_7_8(cmdID, pkt, respBuf, pktSize, respBufLen);
		break;
		/** CMD NOT SUPPORTED **/
		case DEVICE_CONTROL:
			Report("\r Device On/Off\n\r");
			
			respBufLen = snprintf(respBuf, 25, "CMD NOT SUPPORTED ");
			SendStatus_CMD2_4_5_6_7_8(cmdID, pkt, respBuf, pktSize, respBufLen);
		/** CMD NOT SUPPORTED **/
		break;
		case GET_DEVICE_STATUS:
			Report("\r GET_DEVICE_STATUS\n\r");
			respBufLen = snprintf(respBuf, 25, " GET_DEVICE_STATUS ");
			SendStatus_CMD3(cmdID, pkt, respBuf, pktSize, respBufLen);
		break;
		case DEVICE_ON:
			Report("\r DEVICE_ON\n\r");
			status = process_lock_cmd(pkt, pktSize);
			respBufLen = snprintf(respBuf, 25, "Device On SUCCESS ");
			SendStatus_CMD2_4_5_6_7_8(cmdID, pkt, respBuf, pktSize, respBufLen);
		break;
		case DEVICE_OFF:
			Report("\r DEVICE_OFF\n\r");
			status = process_unlock_cmd(pkt, pktSize);
			respBufLen = snprintf(respBuf, 25, "Device Off SUCCESS ");
			SendStatus_CMD2_4_5_6_7_8(cmdID, pkt, respBuf, pktSize, respBufLen);
		break;
		case ADD_KEY:
			Report("\r ADD_KEY\n\r");
			status = process_addkeys_cmd(pkt, pktSize);
			respBufLen = snprintf(respBuf, 25, "KEY ADDED SUCCESS ");
			SendStatus_CMD2_4_5_6_7_8(cmdID, pkt, respBuf, pktSize, respBufLen);
		break;
		case DELETE_KEY:
			Report("\r DELETE_KEY\n\r");
			
			respBufLen = snprintf(respBuf, 25, "KEY DELETED SUCCESS ");
			SendStatus_CMD2_4_5_6_7_8(cmdID, pkt, respBuf, pktSize, respBufLen);
		break;
		case CHANGE_KEY:
			Report("\r CHANGE_KEY\n\r");
			
			respBufLen = snprintf(respBuf, 25, "KEY CHANGED SUCCESS ");
			SendStatus_CMD2_4_5_6_7_8(cmdID, pkt, respBuf, pktSize, respBufLen);
		break;
		
		case GET_KEY_DETAIL:
			Report("\r KEY_DETAIL\n\r");
			
			respBufLen = snprintf(respBuf, 25, "KEY CHANGED SUCCESS ");
			SendStatus_CMD9(cmdID, pkt, respBuf, pktSize, respBufLen);		
			break;
		case KEEP_ALIVE_ACK:
			Report("\rKeep Alive ACK RECV\n\r");
			is_KeepAliveAckRecv = 1;
			break;
			
		default :
			Report("\r Packet Crrupt\n\r");
			break;
	}
	return;
}

/* UNLOCK CMD CMD 11*/
#define CMD_05_LEN					20

#define CMD_05						5
#define CMD_05_CMD_IDX				0x0
#define CMD_05_RANDOM_KEY_IDX		0x1
#define CMD_05_KEY_ADD_IDX			0x7
#define CMD_05_KEY_IDX				0x8
#define CMD_05_MAC_ADD_IDX			0x14

e_cmd_status process_addkeys_cmd (char* pkt,  unsigned int pktSize)
{
	if (uuid_2_handle_found && (current_state & (DEV_NOTI_DONE | RANDOM_KEY_SET))) {
		unsigned char buffer[CMD_05_LEN];
		uint8 noOfKeys = pkt[27];
		uint8 keyIDX = pkt[28];
		memset(buffer, 0x0, CMD_05_LEN);
		
		buffer[CMD_05_CMD_IDX] = CMD_05;
		memcpy(buffer+CMD_05_RANDOM_KEY_IDX, gwRandomKey, GW_RANDOM_KEY_LEN);
		buffer[CMD_05_RANDOM_KEY_IDX+GW_RANDOM_KEY_LEN] = keyIDX;
		
		memcpy(buffer+CMD_05_KEY_IDX, pkt+29, 6);
		memcpy(buffer+CMD_05_MAC_ADD_IDX, gw_wlan_mac, MAC_ADDR_LEN);

		Report("\n\r Add Key Buffer[ ");
		//process_WriteHandle(lock_conn_handle, uuid_4_handle, buffer, CMD_05_LEN);
		for (noOfKeys = 0; noOfKeys < CMD_05_LEN ; noOfKeys++) {
			Report("%x ",buffer[noOfKeys]);
		}
		Report("\n\r");
		
		lastCmdResponse = CMD_EXE_TIMEOUT;
	    current_state |= DEV_CMD_WRITE_EXECUTING;    // Set CMD Executing BIT
		//osi_SyncObjWait(&g_GWUuidWSyncObj, OSI_WAIT_FOREVER); //Wait until the CMD Response Recives;
	    
		current_state &= ~(DEV_CMD_EXECUTING);  // Clear CMD Executing BIT
		
		return lastCmdResponse;
	} else {
		return CMD_ERROR;
	}
}

/* UNLOCK CMD CMD 11*/
#define CMD_06_LEN					20

#define CMD_06						6
#define CMD_06_CMD_IDX				0x0
#define CMD_06_RANDOM_KEY_IDX		0x1
#define CMD_06_KEY_DEL_IDX			0x7
#define CMD_06_MAC_ADD_IDX			0x8

e_cmd_status process_delkeys_cmd (char* pkt,  unsigned int pktSize)
{
	if (uuid_2_handle_found && (current_state & (DEV_NOTI_DONE | RANDOM_KEY_SET))) {
		unsigned char buffer[CMD_06_LEN];
		uint8 noOfKeys = pkt[27];
		uint8 keyIDX = pkt[28];
		memset(buffer, 0x0, CMD_06_LEN);
		
		buffer[CMD_06_CMD_IDX] = CMD_06;
		memcpy(buffer+CMD_06_RANDOM_KEY_IDX, gwRandomKey, GW_RANDOM_KEY_LEN);
		buffer[CMD_06_RANDOM_KEY_IDX+GW_RANDOM_KEY_LEN] = keyIDX;
		
		memcpy(buffer+CMD_06_MAC_ADD_IDX, gw_wlan_mac, MAC_ADDR_LEN);

		Report("\n\r Del Key Buffer[ ");
		//process_WriteHandle(lock_conn_handle, uuid_4_handle, buffer, CMD_06_LEN);
		for (noOfKeys = 0; noOfKeys < CMD_06_LEN ; noOfKeys++) {
			Report("%x ",buffer[noOfKeys]);
		}
		Report("\n\r");
		
		lastCmdResponse = CMD_EXE_TIMEOUT;
	    current_state |= DEV_CMD_WRITE_EXECUTING;    // Set CMD Executing BIT
		//osi_SyncObjWait(&g_GWUuidWSyncObj, OSI_WAIT_FOREVER); //Wait until the CMD Response Recives;
	    
		current_state &= ~(DEV_CMD_EXECUTING);  // Clear CMD Executing BIT
		
		return lastCmdResponse;
	} else {
		return CMD_ERROR;
	}
}

/* UNLOCK CMD CMD 11*/
#define CMD_07_LEN					20

#define CMD_07						7
#define CMD_07_CMD_IDX				0x0
#define CMD_07_RANDOM_KEY_IDX		0x1
#define CMD_07_KEY_ADD_IDX			0x7
#define CMD_07_KEY_IDX				0x8
#define CMD_07_MAC_ADD_IDX			0x14

e_cmd_status process_changekeys_cmd (char* pkt,  unsigned int pktSize)
{
	if (uuid_2_handle_found && (current_state & (DEV_NOTI_DONE | RANDOM_KEY_SET))) {
		unsigned char buffer[CMD_07_LEN];
		uint8 noOfKeys = pkt[27];
		uint8 keyIDX = pkt[28];
		memset(buffer, 0x0, CMD_07_LEN);
		
		buffer[CMD_07_CMD_IDX] = CMD_07;
		memcpy(buffer+CMD_07_RANDOM_KEY_IDX, gwRandomKey, GW_RANDOM_KEY_LEN);
		buffer[CMD_07_RANDOM_KEY_IDX+GW_RANDOM_KEY_LEN] = keyIDX;
		
		memcpy(buffer+CMD_07_KEY_IDX, pkt+29, 6);
		memcpy(buffer+CMD_07_MAC_ADD_IDX, gw_wlan_mac, MAC_ADDR_LEN);

		Report("\n\r Add Key Buffer[ ");
		//process_WriteHandle(lock_conn_handle, uuid_4_handle, buffer, CMD_07_LEN);
		for (noOfKeys = 0; noOfKeys < CMD_07_LEN ; noOfKeys++) {
			Report("%x ",buffer[noOfKeys]);
		}
		Report("\n\r");
		
		lastCmdResponse = CMD_EXE_TIMEOUT;
	    current_state |= DEV_CMD_WRITE_EXECUTING;    // Set CMD Executing BIT
		//osi_SyncObjWait(&g_GWUuidWSyncObj, OSI_WAIT_FOREVER); //Wait until the CMD Response Recives;
	    
		current_state &= ~(DEV_CMD_EXECUTING);  // Clear CMD Executing BIT
		
		return lastCmdResponse;
	} else {
		return CMD_ERROR;
	}
}

/* UNLOCK CMD CMD 11*/
#define CMD_08_LEN					20

#define CMD_08						8
#define CMD_08_CMD_IDX				0x0
#define CMD_08_RANDOM_KEY_IDX		0x1
#define CMD_08_KEY_ADD_IDX			0x7
#define CMD_08_KEY_IDX				0x8
#define CMD_08_MAC_ADD_IDX			0x14

e_cmd_status process_changeMkey_cmd (char* pkt,  unsigned int pktSize)
{
	if (uuid_2_handle_found && (current_state & (DEV_NOTI_DONE | RANDOM_KEY_SET))) {
		unsigned char buffer[CMD_08_LEN];
		uint8 noOfKeys = pkt[27];
		uint8 keyIDX = pkt[28];
		memset(buffer, 0x0, CMD_08_LEN);
		
		buffer[CMD_08_CMD_IDX] = CMD_08;
		memcpy(buffer+CMD_08_RANDOM_KEY_IDX, gwRandomKey, GW_RANDOM_KEY_LEN);
		buffer[CMD_08_RANDOM_KEY_IDX+GW_RANDOM_KEY_LEN] = keyIDX;
		
		memcpy(buffer+CMD_08_KEY_IDX, pkt+29, 6);
		memcpy(buffer+CMD_08_MAC_ADD_IDX, gw_wlan_mac, MAC_ADDR_LEN);

		Report("\n\r Add Key Buffer[ ");
		//process_WriteHandle(lock_conn_handle, uuid_4_handle, buffer, CMD_08_LEN);
		for (noOfKeys = 0; noOfKeys < CMD_08_LEN ; noOfKeys++) {
			Report("%x ",buffer[noOfKeys]);
		}
		Report("\n\r");
		
		lastCmdResponse = CMD_EXE_TIMEOUT;
	    current_state |= DEV_CMD_WRITE_EXECUTING;    // Set CMD Executing BIT
		//osi_SyncObjWait(&g_GWUuidWSyncObj, OSI_WAIT_FOREVER); //Wait until the CMD Response Recives;
	    
		current_state &= ~(DEV_CMD_EXECUTING);  // Clear CMD Executing BIT
		
		return lastCmdResponse;
	} else {
		return CMD_ERROR;
	}
}

/* UNLOCK CMD CMD 11*/
#define CMD_11_LEN					13

#define CMD_11						11
#define CMD_11_CMD_IDX				0x0
#define CMD_11_RANDOM_KEY_IDX		0x1
#define CMD_11_MAC_ADD_IDX			0x7

e_cmd_status process_unlock_cmd (char* pkt,  unsigned int pktSize)
{
	if (uuid_4_handle_found && (current_state & (DEV_NOTI_DONE | RANDOM_KEY_SET))) {
		unsigned char buffer[CMD_11_LEN];
		int loop = 0;
		buffer[CMD_11_CMD_IDX] = CMD_11;
		memcpy(buffer+CMD_11_RANDOM_KEY_IDX, gwRandomKey, GW_RANDOM_KEY_LEN);
		memcpy(buffer+CMD_11_MAC_ADD_IDX, gw_wlan_mac, MAC_ADDR_LEN);

		process_WriteHandle(lock_conn_handle, uuid_4_handle, buffer, CMD_11_LEN);
		
		Message("\r\nUnlock :- ");
		for(loop = 0 ; loop < CMD_11_LEN ; loop++)
			Report("[%x] ", buffer[loop]);
		Message("\r\n");
		
		lastCmdResponse = CMD_EXE_TIMEOUT;
	    current_state |= DEV_CMD_WRITE_EXECUTING;    // Set CMD Executing BIT
		//osi_SyncObjWait(&g_GWUuidWSyncObj, OSI_WAIT_FOREVER); //Wait until the CMD Response Recives;
	    
		current_state &= ~(DEV_CMD_EXECUTING);  // Clear CMD Executing BIT
		
		return lastCmdResponse;
	} else {
		return CMD_ERROR;
	}
}

/* LOCK CMD 12*/
#define CMD_12_LEN				7

#define CMD_12						12
#define CMD_12_IDX				0x0
#define CMD_12_MAC_ADD_IDX			0x1

e_cmd_status process_lock_cmd (char* pkt,  unsigned int pktSize)
{
	if (uuid_4_handle_found && (current_state & (DEV_NOTI_DONE | RANDOM_KEY_SET))) {
		unsigned char buffer[CMD_12_LEN];
		int loop = 0;
		
		buffer[CMD_12_IDX] = CMD_12;
		memcpy(buffer+CMD_12_MAC_ADD_IDX, gw_wlan_mac, MAC_ADDR_LEN);

		process_WriteHandle(lock_conn_handle, uuid_4_handle, buffer, CMD_12_LEN);
		Message("\r\nLock :- ");
		for(loop = 0 ; loop < CMD_12_LEN ; loop++)
			Report("[%x] ", buffer[loop]);
		Message("\r\n");
		lastCmdResponse = CMD_EXE_TIMEOUT;
	    current_state |= DEV_CMD_WRITE_EXECUTING;    // Set CMD Executing BIT
		//osi_SyncObjWait(&g_GWUuidWSyncObj, OSI_WAIT_FOREVER); //Wait until the CMD Response Recives;
	    
		current_state &= ~(DEV_CMD_EXECUTING);  // Clear CMD Executing BIT
		
		return lastCmdResponse;
	} else {
		return CMD_ERROR;
	}
}

static int SendStatus_CMD2_4_5_6_7_8 (char cmdID, char* pkt, char* respMsg, unsigned int pktSize, unsigned int respMsgLen)
{
	unsigned int i = 0;
	char *respBuffer;
	unsigned int pktLen;
	long lRetVal = -1;
	
	Report("\r {%s}\n\r", __FUNCTION__);
	
	//Report("[%x] [%d:%d:%d:%d] %d\n\r",T, pkt[0], pkt[1], pkt[2], pkt[3], sizeof(T));
	/********************************
	pktLen = PKT_LEN
			 +CMD_ID_LEN
			 +TOKEN_LEN
			 +DEVICE_ON_MSG_CODE_LEN
			 +DEVICE_ON_MSG_LEN;
	*********************************/
	pktLen = 37;
	respBuffer = (char*)malloc(pktLen);
	if (respBuffer) {
		respBuffer[0] =  0; //(pktLen >> 8) && 0xFF;
		respBuffer[1] = 37; //(pktLen) && 0xFF;
		
		respBuffer[2] = cmdID;
		
		respBuffer[3] = pkt[0];
		respBuffer[4] = pkt[1];
		respBuffer[5] = pkt[2];
		respBuffer[6] = pkt[3];
		respBuffer[7] = pkt[4];
		respBuffer[8] = pkt[5];
		respBuffer[9] = pkt[6];
		respBuffer[10]= pkt[7];
		
		respBuffer[11] = 1;
		
		#if 0x0
		/* Check Response Message Overflow */
		if (respMsgLen < 25) {
			memcpy(respBuffer+12, respMsg, respMsgLen);
			memset(respBuffer+respMsgLen, '$',25-respMsgLen);
		}
		else {
			memcpy(respBuffer+12, respMsg, 25);
		}
		#else
			memset(respBuffer+12, '*', 25);
		#endif
		
		Report("\n\r RESP PKT :- ");
		for(i = 0 ; i < pktLen ; i++) {
			if(i < 12)
				Report("%d{%d}", i, respBuffer[i]);
			else
				Report("%d{%c}", i, respBuffer[i]);
		}
		
		lRetVal = sl_Send(iSockID, respBuffer, pktLen , 0 );
		if( lRetVal < 0 )
		{
			// error
			Report("\n\rERROR IN SEND\n\r");
			sl_Close(iSockID);
			free(respBuffer);
			ASSERT_ON_ERROR(SEND_ERROR);
		}
		Report("\n\r");
		free(respBuffer);
	}	

	return 1;
}

static int SendStatus_CMD3(char cmdID, char* pkt, char* respMsg, unsigned int pktSize, unsigned int respMsgLen)
{
	unsigned int i = 0;
	char *respBuffer;
	unsigned int pktLen;
	long lRetVal = -1;
	
	Report("\r {%s}\n\r", __FUNCTION__);
	
	//Report("[%x] [%d:%d:%d:%d] %d\n\r",T, pkt[0], pkt[1], pkt[2], pkt[3], sizeof(T));
	/********************************
	pktLen = PKT_LEN					2
			 +CMD_ID_LEN				1
			 +TOKEN_LEN					8
			 +RETURN_MSG_CODE		    1
			 +RETURN_MSG		        25
			 +DEVICE_COUNT				1
			 +DEVICE_ID					6
			 +DEVICE_NAME				25
			 +DEVICE_CAT				1
			 +DEVICE_STATUS				1
			 +DEVICE_IS_CONNECTED		1
	*********************************/
	pktLen = 72;
	
	respBuffer = (char*)malloc(pktLen);
	if (respBuffer) {
		respBuffer[0] =  0; //(pktLen >> 8) && 0xFF;
		respBuffer[1] = 72; //(pktLen) && 0xFF;
		
		respBuffer[2] = cmdID;
		
		respBuffer[3] = pkt[0];
		respBuffer[4] = pkt[1];
		respBuffer[5] = pkt[2];
		respBuffer[6] = pkt[3];
		respBuffer[7] = pkt[4];
		respBuffer[8] = pkt[5];
		respBuffer[9] = pkt[6];
		respBuffer[10]= pkt[7];
		
		respBuffer[11] = 1;
		
		/* Check Response Message Overflow */
		#if 0x0
		if (respMsgLen < 25) {
			memcpy(respBuffer+12, respMsg, respMsgLen);
			memset(respBuffer+respMsgLen, '$',25-respMsgLen);
		}
		else {
			memcpy(respBuffer+12, respMsg, 25);
		}
		#else
			memset(respBuffer+12, '*', 25);
		#endif
		
		respBuffer[37] = 1; //DEVICE_COUNT
		memcpy(respBuffer+38, "D11211", 6);
		memcpy(respBuffer+44, "Front Door Lock**********", 25);
		
		respBuffer[69] = 0x05;
		respBuffer[71] = 0x01;
		respBuffer[72] = 0x01;
		
		//Report("\n\r RESP PKT Sending CMD3");
		#if 0
		for(i = 0 ; i < pktLen ; i++) {
			if(i < 12)
				Report("%d{%d}", i, respBuffer[i]);
			else
				Report("%d{%c}", i, respBuffer[i]);
		}
		#endif
		lRetVal = sl_Send(iSockID, respBuffer, pktLen , 0 );
		if( lRetVal < 0 )
		{
			// error
			Report("\n\rERROR IN SEND\n\r");
			sl_Close(iSockID);
			free(respBuffer);
			ASSERT_ON_ERROR(SEND_ERROR);
		}
		//Report("\n\r");
		free(respBuffer);
	}	
	return 1;
}



static int SendStatus_CMD9(char cmdID, char* pkt, char* respMsg, unsigned int pktSize, unsigned int respMsgLen)
{
	unsigned int i = 0;
	char *respBuffer;
	unsigned int pktLen;
	long lRetVal = -1;
	
	Report("\r {%s}\n\r", __FUNCTION__);
	
	//Report("[%x] [%d:%d:%d:%d] %d\n\r",T, pkt[0], pkt[1], pkt[2], pkt[3], sizeof(T));
	/********************************
	pktLen =  PKT_LEN					2
			 +CMD_ID_LEN				1
			 +TOKEN_LEN					8
			 +RETURN_MSG_CODE		    1
			 +RETURN_MSG		        25
			 +KEY_COUNT					1
			 +DEVICE_ID					6
			 +DEVICE_NAME				25
			 +DEVICE_CAT				1
			 +DEVICE_STATUS				1
			 +DEVICE_IS_CONNECTED		1
	*********************************/
	pktLen = 55;
	
	respBuffer = (char*)malloc(pktLen);
	if (respBuffer) {
		respBuffer[0] =  0; //(pktLen >> 8) && 0xFF;
		respBuffer[1] = 55; //(pktLen) && 0xFF;
		
		respBuffer[2] = cmdID;
		
		respBuffer[3] = pkt[0];
		respBuffer[4] = pkt[1];
		respBuffer[5] = pkt[2];
		respBuffer[6] = pkt[3];
		respBuffer[7] = pkt[4];
		respBuffer[8] = pkt[5];
		respBuffer[9] = pkt[6];
		respBuffer[10]= pkt[7];
		
		respBuffer[11] = 1;
		
		/* Check Response Message Overflow */
		#if 0x0
		if (respMsgLen < 25) {
			memcpy(respBuffer+12, respMsg, respMsgLen);
			memset(respBuffer+respMsgLen, '$',25-respMsgLen);
		}
		else {
			memcpy(respBuffer+12, respMsg, 25);
		}
		#else
			memset(respBuffer+12, '*', 25);
		#endif
		
		respBuffer[37] = 1; //KEY_COUNT
		respBuffer[38] = 1; //KEY_IDX
		memset(respBuffer+39, '*', 15);
		respBuffer[54] = 0x01;
		
		//Report("\n\r RESP PKT Sending CMD3");
		#if 0
		for(i = 0 ; i < pktLen ; i++) {
			if(i < 12)
				Report("%d{%d}", i, respBuffer[i]);
			else
				Report("%d{%c}", i, respBuffer[i]);
		}
		#endif
		lRetVal = sl_Send(iSockID, respBuffer, pktLen , 0 );
		if( lRetVal < 0 )
		{
			// error
			Report("\n\rERROR IN SEND\n\r");
			sl_Close(iSockID);
			free(respBuffer);
			ASSERT_ON_ERROR(SEND_ERROR);
		}
		//Report("\n\r");
		free(respBuffer);
	}	
	return 1;
}

//*****************************************************************************
//
//*****************************************************************************
void GW_GenericTask_Init()
{

  //
  // Create sync object to signal Sl_Start and Wlan Connect complete
  //
  osi_SyncObjCreate(&g_GWGenSyncObj);
  osi_SyncObjCreate(&g_GWConSyncObj);
  osi_SyncObjCreate(&g_GWUuidWSyncObj);
  
  //
  // Create sync object to signal Sl_Start and Wlan Connect complete
  //
  osi_SyncObjCreate(&g_NetStatSyncObj);
  /*Initialize Gateway Button*/
  //  Button2Init();

  //Wifi_GetMAC(gw_wlan_mac);
  Report("System MAC ADD [0x%2x:0x%2x:0x%2x:0x%2x:0x%2x:0x%2x]\n", gw_wlan_mac[0], gw_wlan_mac[1], gw_wlan_mac[2], gw_wlan_mac[3], gw_wlan_mac[4], gw_wlan_mac[5]);
  InitSocket();
  //
  // GW Generic Task
  //
  osi_TaskCreate(GwGenericTask,
                  (const signed char *)"GW generic",
                  GENERIC_TASK_STACK_SIZE,
                  NULL,
                  1,
                  NULL );

#if 0
  //
  // GW KEEP ALIVE
  //  
  osi_TaskCreate(GwKeepAliveTask,
                  (const signed char *)"GW Keep Alive",
                  644,
                  NULL,
                  1,
                  NULL );
#endif

  	Report("Generic_task Rigister gw Event and Data\n");
	RegisterGwCB(GW_EVENT_CB,GW_EventCb);

	RegisterGwCB(GW_DATA_CB,GW_DataCb);
}

void KickGenericTask()
{
	osi_SyncObjSignal(&g_GWGenSyncObj);
}


unsigned int * cc26xxCRC;
void *  bonds;


void LoadBleFiCfg()
{
//	blefiCfgInit();
	is_blefiCfgReady = true;
}

void UpdateBlefiCfg()
{
	is_blefiCfgupdate = true;
}

/*Gateway Button handler*/
void GwButtonHandler()
{

	Message("\n\r[GW] Scan Button Pressed. discovering devices...");
	//Button2IntDisable();
	//Button2IntClear();
	//Signal for the scan
	autoScanTimeout = 0xFFFF;
}


/*Initialize Gateway Button*/
void Gateway_ButtonInit()
{
	//Button2Init();
}

int configureAutoScan(unsigned int timeout)
{
	if(timeout>AUTO_SCAN_MAX_VALUE)
	{
		return -1;
	}
	else if(timeout < AUTO_SCAN_MIN_VALUE)
	{
		*(blefiCfgRec.autoScan) = 0;
	}
	else
	{
		*(blefiCfgRec.autoScan) = timeout;
	}

	UpdateBlefiCfg();
	return((int)*(blefiCfgRec.autoScan));
}

int readAutoScan()
{
	return((int)*(blefiCfgRec.autoScan));
}

void enforceCC26XXFwChecsum(unsigned int checksum)
{
	*(blefiCfgRec.cc26xxCRC) = 0x0;
	UpdateBlefiCfg();

}

void doHandleCmdtimeout()
{
	if (GC_IsBLEReady() != true)
	{
		return;
	}
	DB_FlushSyncObjects();
}

void disableAutoconnect()
{
	*(blefiCfgRec.autocon) = AUTO_CON_DISABLE;
	UpdateBlefiCfg();
}

void enableAutoconnect()
{
	*(blefiCfgRec.autocon) = AUTO_CON_ENABLE;
	UpdateBlefiCfg();
}


void signalWLANConnect()
{
	//
	// Signal Wlan COnnect
	//
	osi_SyncObjSignal(&g_NetStatSyncObj);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
