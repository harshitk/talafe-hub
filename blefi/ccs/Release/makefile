################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS

GEN_OPTS__FLAG := --cmd_file="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/compiler.opt"
GEN_CMDS__FLAG := -l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/linker.cmd"

ORDERED_OBJS += \
"./blefi_gpio_if.obj" \
"./cc26xxdnld.obj" \
"./cc3200.obj" \
"./generic_task.obj" \
"./main.obj" \
"./pinmux.obj" \
"./uart_if.obj" \
"./wifi/otatask.obj" \
"./wifi/smartconfig.obj" \
"./wifi/wifi.obj" \
"../cc3200v1p32.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/ota/ccs/Release/ota.a" \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink_extlib/flc/ccs/Release/flc.a" \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib/ccs/ti_rtos/ti_rtos.a" \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/ccs/Debug/cli.a" \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/ccs/Debug/npi.a" \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/ccs/Debug/gateway.a" \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib/ccs/Release/driverlib.a" \
-l"C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/ccs/OS/simplelink.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include wifi/subdir_vars.mk
-include subdir_rules.mk
-include wifi/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
blefi.out \

EXE_OUTPUTS__QUOTED += \
"blefi.out" \

BIN_OUTPUTS += \
blefi.bin \

BIN_OUTPUTS__QUOTED += \
"blefi.bin" \


# All Target
all: blefi.out

dependents:
	-cd C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default && $(MAKE) all

# Tool invocations
blefi.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS) C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/linker.cmd
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -O1 --preinclude="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/mqtt_app/include" -g --gcc --define=__CCS__ --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=PLATFORM_LP --define=cc3200 --define=CC3200_BLE --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL --define=BLEFI_BOARD_V2 --define=CENTRAL_CFG=0x8 --define=HEAPMGR_SIZE=4096 --define=HOST_CONFIG=CENTRAL_CFG --define=TI_DRIVERS_GPIO_INCLUDED --define=TI_DRIVERS_SPI_INCLUDED --define=USE_ICALL --define=USE_TIRTOS --define=INT_HEAP_LEN=4096 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi -z -m"blefi.map" --stack_size=0x00001000 --heap_size=0x0000A000 -i"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/lib" -i"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --reread_libs --diag_wrap=off --warn_sections --display_error_number --xml_link_info="blefi_linkInfo.xml" --rom_model -o "blefi.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

blefi.bin: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armhex"  -o "blefi.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "blefi_gpio_if.d" "cc26xxdnld.d" "cc3200.d" "generic_task.d" "main.d" "pinmux.d" "uart_if.d" "wifi\otatask.d" "wifi\smartconfig.d" "wifi\wifi.d" 
	-$(RM) "blefi_gpio_if.obj" "cc26xxdnld.obj" "cc3200.obj" "generic_task.obj" "main.obj" "pinmux.obj" "uart_if.obj" "wifi\otatask.obj" "wifi\smartconfig.obj" "wifi\wifi.obj" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-@echo 'Converting to bin'
	-"C:/ti/ccsv6/utils/tiobj2bin/tiobj2bin" "blefi.out" "blefi.bin" "C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armofd" "C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armhex" "C:/ti/ccsv6/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/linker.cmd:

-include ../makefile.targets

