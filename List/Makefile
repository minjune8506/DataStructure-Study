CC = gcc
ARRAY_LIST = arraylist
ARRAY_LIST_OBJS = arraylist.o arraylistMain.o
CIRCULAR_LIST = circularlist
CIRCULAR_LIST_OBJS = circularlist.o circularlistMain.o
DOUBLY_LIST = doublylist
DOUBLY_LIST_OBJS = doublylist.o doublylistMain.o
LINKED_LIST = linkedlist
LINKED_LIST_OBJS = linkedlist.o linkedlistMain.o

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all : arraylist circularlist doublylist linkedlist

arraylist : $(ARRAY_LIST_OBJS)
	@ echo "$(BLUE)Array List Object File Created$(RESET)"
	@ $(CC) $(ARRAY_LIST_OBJS) -o $(ARRAY_LIST)
	@ echo "$(RED)Array List Created$(RESET)"

circularlist : $(CIRCULAR_LIST_OBJS)
	@ echo "$(BLUE)Circular List Object File Created$(RESET)"
	@ $(CC) $(CIRCULAR_LIST_OBJS) -o $(CIRCULAR_LIST)
	@ echo "$(RED)Circular List Created$(RESET)"

doublylist : $(DOUBLY_LIST_OBJS)
	@ echo "$(BLUE)Doubly List Object File Created$(RESET)"
	@ $(CC) $(DOUBLY_LIST_OBJS) -o $(DOUBLY_LIST)
	@ echo "$(RED)Doubly List Created$(RESET)"

linkedlist : $(LINKED_LIST_OBJS)
	@ echo "$(BLUE)Linked List Object File Created$(RESET)"
	@ $(CC) $(LINKED_LIST_OBJS) -o $(LINKED_LIST)
	@ echo "$(RED)Linked List Created$(RESET)"

%.o : %.c
	@ $(CC) -c $< -o $@

clean :
	@ rm -f $(ARRAY_LIST_OBJS) $(CIRCULAR_LIST_OBJS) $(DOUBLY_LIST_OBJS) $(LINKED_LIST_OBJS)
	@ echo "$(RED)Object File Removed$(RESET)"

fclean : clean
	@ rm -f $(ARRAY_LIST) $(CIRCULAR_LIST) $(DOUBLY_LIST) $(LINKED_LIST)
	@ echo "$(RED)Executable Files Removed$(RESET)"

re : fclean all
