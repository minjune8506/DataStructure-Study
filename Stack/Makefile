CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = linkedstack.o arraystack.o linkedStackMain.o arrayStackMain.o
TARGET = arraystack linkedstack

RED = \033[2;31m
BLUE = \033[1;34m
RESET = \033[0m

all : $(TARGET)

$(TARGET) : $(OBJS)
	@ echo "$(RED)Object Files Created$(RESET)"
	@ $(CC) -o arraystack arraystack.o arrayStackMain.o
	@ $(CC) -o linkedstack linkedstack.o linkedStackMain.o 
	@ echo "$(BLUE)Target Created$(RESET)"

linkedstack.o : linkedstack.c linkedstack.h
	@ $(CC) -c linkedstack.c linkedStackMain.c

arraystack.o : arraystack.c arraystack.h
	@ $(CC) -c arraystack.c arrayStackMain.c

clean :
	@ rm -f $(OBJS)
	@ echo "$(RED)Remove Object Files$(RESET)"

fclean : clean
	@ rm -f arraystack linkedstack
	@ echo "$(RED)Remove Executable files$(RESET)"

re : fclean all
