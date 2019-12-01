################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../util/Date.cpp 

OBJS += \
./util/Date.o 

CPP_DEPS += \
./util/Date.d 


# Each subdirectory must supply rules for building sources it contributes
util/%.o: ../util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -include"/home/etudiant/Bureau/Programmation/TP3/contrat/ContratException.cpp" -include"/home/etudiant/Bureau/Programmation/TP3/util/Date.cpp" -include"/home/etudiant/Bureau/Programmation/TP3/util/Date.h" -include"/home/etudiant/Bureau/Programmation/TP3/contrat/ContratException.h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


