CC = gcc
ARRAY_LIST = arraylist
CIRCULAR_LIST = circularlist
DOUBLY_LIST = doublylist
LINKED_LIST = linkedlist

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all : arraylist circularlist doublylist linkedlist

arraylist : arraylist.o
	@ echo "$(BLUE)Array List Object File Created$(RESET)"
	@ $(CC) arraylist.o -o $(ARRAY_LIST)
	@ echo "$(RED)Array List Created$(RESET)"

circularlist : circularlist.o
	@ echo "$(BLUE)Circular List Object File Created$(RESET)"
	@ $(CC) circularlist.o -o $(CIRCULAR_LIST)
	@ echo "$(RED)Circular List Created$(RESET)"

doublylist : doublylist.o
	@ echo "$(BLUE)Doubly List Object File Created$(RESET)"
	@ $(CC) doublylist.o -o $(DOUBLY_LIST)
	@ echo "$(RED)Doubly List Created$(RESET)"

linkedlist : linkedlist.o
	@ echo "$(BLUE)Linked List Object File Created$(RESET)"
	@ $(CC) linkedlist.o -o $(LINKED_LIST)
	@ echo "$(RED)Linked List Created$(RESET)"

%.o : %.c
	@ $(CC) -c $< -o $@

clean :
	@ rm -f arraylist.o circularlist.o doublylist.o linkedlist.o
	@ echo "$(RED)Object File Removed$(RESET)"

fclean : clean
	@ rm -f $(ARRAY_LIST) $(CIRCULAR_LIST) $(DOUBLY_LIST) $(LINKED_LIST)
	@ echo "$(RED)Executable Files Removed$(RESET)"

re : fclean all
