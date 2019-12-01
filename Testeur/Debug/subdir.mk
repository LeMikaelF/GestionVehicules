################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camion_Testeur.cpp \
../Proprietaire_Testeur.cpp \
../VehiculePromenade_Testeur.cpp \
../Vehicule_Testeur.cpp 

OBJS += \
./Camion_Testeur.o \
./Proprietaire_Testeur.o \
./VehiculePromenade_Testeur.o \
./Vehicule_Testeur.o 

CPP_DEPS += \
./Camion_Testeur.d \
./Proprietaire_Testeur.d \
./VehiculePromenade_Testeur.d \
./Vehicule_Testeur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/etudiant/Bureau/TP4/source" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


