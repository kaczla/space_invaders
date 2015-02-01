################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ammo.cpp \
../src/enemy.cpp \
../src/engine.cpp \
../src/game.cpp \
../src/main.cpp \
../src/menu.cpp \
../src/npc.cpp \
../src/player.cpp \
../src/stats.cpp \
../src/template.cpp 

OBJS += \
./src/ammo.o \
./src/enemy.o \
./src/engine.o \
./src/game.o \
./src/main.o \
./src/menu.o \
./src/npc.o \
./src/player.o \
./src/stats.o \
./src/template.o 

CPP_DEPS += \
./src/ammo.d \
./src/enemy.d \
./src/engine.d \
./src/game.d \
./src/main.d \
./src/menu.d \
./src/npc.d \
./src/player.d \
./src/stats.d \
./src/template.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


