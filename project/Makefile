COMMON_OBJECTS	=
CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/mps430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: toy.elf

install:
	cd ../; make all

toy.elf: ${COMMON_OBJECTS} main.o state_machines.o led.o switches.o buzzer.o interrupt_handler.o drawing.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a ../lib/libLcd.a

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf
	cd .. && rm -rf h lib

led.o: led.c led.h switches.h

switches.c: switches.h

buzzer.c: buzzer.h

interrupt_handler.o: state_machines.h

stateMachines.o: led.h buzzer.h state_machines.h switches.h
