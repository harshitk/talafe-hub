################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
blefi_gpio_if.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/blefi_gpio_if.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/source" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="blefi_gpio_if.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cc26xxdnld.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cc26xxdnld.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/source" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="cc26xxdnld.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cc3200.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cc3200.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/source" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="cc3200.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

generic_task.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/generic_task.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/source" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="generic_task.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/source" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pinmux.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/pinmux.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/source" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="pinmux.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart_if.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/uart_if.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/source" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="uart_if.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


