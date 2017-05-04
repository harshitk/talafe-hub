################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS

GEN_OPTS__FLAG := --cmd_file="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/compiler.opt"
GEN_CMDS__FLAG := "C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/linker.cmd"

ORDERED_OBJS += \
"./ble_central.obj" \
"./database.obj" \
"./gapbondmgr.obj" \
"./gateway_api.obj" \
"./gateway_cmds.obj" \
"./gateway_events.obj" \
"./gateway_task.obj" \
$(GEN_CMDS__FLAG) \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
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
LIB_OUTPUTS += \
gateway.a \

LIB_OUTPUTS__QUOTED += \
"gateway.a" \


# All Target
all: gateway.a

dependents:
	-cd C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default && $(MAKE) clean all

# Tool invocations
gateway.a: $(OBJS) C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/linker.cmd
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Archiver'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armar" r "gateway.a" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(LIB_OUTPUTS__QUOTED)
	-$(RM) "ble_central.d" "database.d" "gapbondmgr.d" "gateway_api.d" "gateway_cmds.d" "gateway_events.d" "gateway_task.d" 
	-$(RM) "ble_central.obj" "database.obj" "gapbondmgr.obj" "gateway_api.obj" "gateway_cmds.obj" "gateway_events.obj" "gateway_task.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/ti_rtos/ti_rtos_config/ccs/Default/configPkg/linker.cmd:

-include ../makefile.targets

