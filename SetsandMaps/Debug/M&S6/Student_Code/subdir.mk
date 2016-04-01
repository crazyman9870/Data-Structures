################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../M&S6/Student_Code/Factory.cpp \
../M&S6/Student_Code/GPA.cpp \
../M&S6/Student_Code/Student.cpp 

OBJS += \
./M&S6/Student_Code/Factory.o \
./M&S6/Student_Code/GPA.o \
./M&S6/Student_Code/Student.o 

CPP_DEPS += \
./M&S6/Student_Code/Factory.d \
./M&S6/Student_Code/GPA.d \
./M&S6/Student_Code/Student.d 


# Each subdirectory must supply rules for building sources it contributes
M&S6/Student_Code/%.o: ../M&S6/Student_Code/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


