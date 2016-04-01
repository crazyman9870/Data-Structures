################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../To\ Students/Student_Code/Factory.cpp \
../To\ Students/Student_Code/GPA.cpp \
../To\ Students/Student_Code/Student.cpp 

OBJS += \
./To\ Students/Student_Code/Factory.o \
./To\ Students/Student_Code/GPA.o \
./To\ Students/Student_Code/Student.o 

CPP_DEPS += \
./To\ Students/Student_Code/Factory.d \
./To\ Students/Student_Code/GPA.d \
./To\ Students/Student_Code/Student.d 


# Each subdirectory must supply rules for building sources it contributes
To\ Students/Student_Code/Factory.o: ../To\ Students/Student_Code/Factory.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"To Students/Student_Code/Factory.d" -MT"To\ Students/Student_Code/Factory.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

To\ Students/Student_Code/GPA.o: ../To\ Students/Student_Code/GPA.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"To Students/Student_Code/GPA.d" -MT"To\ Students/Student_Code/GPA.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

To\ Students/Student_Code/Student.o: ../To\ Students/Student_Code/Student.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"To Students/Student_Code/Student.d" -MT"To\ Students/Student_Code/Student.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


