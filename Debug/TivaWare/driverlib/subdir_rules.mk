################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
TivaWare/driverlib/%.obj: ../TivaWare/driverlib/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS" --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS/FreeRTOS-Kernel/Source/include" --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS/FreeRTOS-Kernel/Source/portable/CCS/ARM_CM4F" --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS/TivaWare" --include_path="C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="TivaWare/driverlib/$(basename $(<F)).d_raw" --obj_directory="TivaWare/driverlib" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

TivaWare/driverlib/%.obj: ../TivaWare/driverlib/%.s $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS" --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS/FreeRTOS-Kernel/Source/include" --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS/FreeRTOS-Kernel/Source/portable/CCS/ARM_CM4F" --include_path="C:/Users/Manuel/Documents/TI FreeRTOS/Tiva1294XL_FreeRTOS/TivaWare" --include_path="C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="TivaWare/driverlib/$(basename $(<F)).d_raw" --obj_directory="TivaWare/driverlib" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


