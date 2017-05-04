################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
schema.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/schema/schema.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --abi=eabi -me -O1 --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common" --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/schema/include" -g --gcc --define=cc3200 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="schema.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


