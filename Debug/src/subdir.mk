################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Policy.cpp \
../src/PolicyFIFO.cpp \
../src/PolicyFIFO_test.cpp \
../src/PolicyOptimal.cpp \
../src/Util.cpp 

OBJS += \
./src/Policy.o \
./src/PolicyFIFO.o \
./src/PolicyFIFO_test.o \
./src/PolicyOptimal.o \
./src/Util.o 

CPP_DEPS += \
./src/Policy.d \
./src/PolicyFIFO.d \
./src/PolicyFIFO_test.d \
./src/PolicyOptimal.d \
./src/Util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


