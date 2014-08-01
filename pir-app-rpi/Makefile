
# Variables
DEBUG=yes
CC=gcc
CCPREFIX=~/rpi-tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-

ifeq ($(DEBUG),yes)
	CFLAGS=-W -Wall -ansi -pedantic -g
	LDFLAGS=
else
	CFLAGS=-W -Wall -ansi -pedantic
	LDFLAGS=
endif

EXEC=pir-sensor-app
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Compilation in debug mode"
else
	@echo "Compilation in release mode"
endif

$(EXEC): $(OBJ)
	$(CCPREFIX)$(CC) -o $@ $^ $(LDFLAGS)

main.o: #file.h

%.o: %.c
	$(CCPREFIX)$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf $(EXEC)
