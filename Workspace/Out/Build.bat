@echo off
arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7e-m -mthumb -save-temps -nostdlib -O0 -Wl,-Map,"App_Main.map" -Wl,-T"tm4c123gh6pm.lds" ../MCAL/CPU/CPU.c startupCode.c ../Application/app_main.c -o Exe/app_Out.elf
pause
