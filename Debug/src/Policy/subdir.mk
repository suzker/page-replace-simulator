################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Policy/Policy.cpp \
../src/Policy/PolicyFIFO.cpp \
../src/Policy/PolicyLFU.cpp \
../src/Policy/PolicyLRUClock.cpp \
../src/Policy/PolicyLRUREF8.cpp \
../src/Policy/PolicyLRUStack.cpp \
../src/Policy/PolicyOptimal.cpp 

OBJS += \
./src/Policy/Policy.o \
./src/Policy/PolicyFIFO.o \
./src/Policy/PolicyLFU.o \
./src/Policy/PolicyLRUClock.o \
./src/Policy/PolicyLRUREF8.o \
./src/Policy/PolicyLRUStack.o \
./src/Policy/PolicyOptimal.o 

CPP_DEPS += \
./src/Policy/Policy.d \
./src/Policy/PolicyFIFO.d \
./src/Policy/PolicyLFU.d \
./src/Policy/PolicyLRUClock.d \
./src/Policy/PolicyLRUREF8.d \
./src/Policy/PolicyLRUStack.d \
./src/Policy/PolicyOptimal.d 


# Each subdirectory must supply rules for building sources it contributes
src/Policy/%.o: ../src/Policy/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


