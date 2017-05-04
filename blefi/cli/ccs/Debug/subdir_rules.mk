################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
cli.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/cli.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --abi=eabi -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" -g --gcc --define=cc3200 --define=BLEFI_BOARD_V2 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="cli.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cli_handler.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/cli_handler.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --abi=eabi -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" -g --gcc --define=cc3200 --define=BLEFI_BOARD_V2 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="cli_handler.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

conversions.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/conversions.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --abi=eabi -me -O1 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/wifi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/cli/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" -g --gcc --define=cc3200 --define=BLEFI_BOARD_V2 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="conversions.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


