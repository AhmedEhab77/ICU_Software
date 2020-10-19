################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/External\ Interrupt/EXT_Prog.c 

OBJS += \
./MCAL/External\ Interrupt/EXT_Prog.o 

C_DEPS += \
./MCAL/External\ Interrupt/EXT_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/External\ Interrupt/EXT_Prog.o: ../MCAL/External\ Interrupt/EXT_Prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"MCAL/External Interrupt/EXT_Prog.d" -MT"MCAL/External\ Interrupt/EXT_Prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


