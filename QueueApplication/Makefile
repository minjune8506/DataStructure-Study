CC = gcc
TARGET = simulation
OBJS = simulation.o

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all : $(TARGET)

$(TARGET) : $(OBJS)
	@ echo "$(BLUE)Object File Created$(RESET)"
	@ $(CC) $(OBJS) -o $(TARGET)
	@ echo "$(RED)simulation Created$(RESET)"

%.o : %.c
	@ $(CC) -c $< -o $@

clean :
	@ rm -f $(OBJS)
	@ echo "$(RED)Object File Removed$(RESET)"

fclean : clean
	@ rm -f $(TARGET)
	@ echo "$(RED)simulation Removed$(RESET)"

re : fclean all

