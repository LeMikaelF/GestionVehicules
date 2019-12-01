################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camion.cpp \
../ContratException.cpp \
../Date.cpp \
../Proprietaire.cpp \
../Vehicule.cpp \
../VehiculeException.cpp \
../VehiculePromenade.cpp \
../validationFormat.cpp 

OBJS += \
./Camion.o \
./ContratException.o \
./Date.o \
./Proprietaire.o \
./Vehicule.o \
./VehiculeException.o \
./VehiculePromenade.o \
./validationFormat.o 

CPP_DEPS += \
./Camion.d \
./ContratException.d \
./Date.d \
./Proprietaire.d \
./Vehicule.d \
./VehiculeException.d \
./VehiculePromenade.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


