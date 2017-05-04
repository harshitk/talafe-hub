################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
CC2650_SensorTag.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/mqtt_app/CC2650_SensorTag.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -Ooff --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/schema/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/netapps/mqtt/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/mqtt_app/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" -g --gcc --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="CC2650_SensorTag.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

device_mqtt.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/mqtt_app/device_mqtt.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -Ooff --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/schema/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/netapps/mqtt/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/mqtt_app/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" -g --gcc --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="device_mqtt.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mqtt_app_main.obj: C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/mqtt_app/mqtt_app_main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -Ooff --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/npi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/schema/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/netapps/mqtt/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/gateway/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/blefi/mqtt_app/" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/driverlib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/simplelink/include" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/oslib" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/example/common" --include_path="C:/ti/BleToWifiGateway_1.0.0_20_oct_16/src/inc" -g --gcc --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="mqtt_app_main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


