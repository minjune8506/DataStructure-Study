CC = gcc
ARRAY_QUEUE = arrayqueue
LINKED_DEQUEUE = linkeddeque
ARRAY_OBJS = arrayqueue.o arrayQueueMain.o
LINKED_OBJS = linkeddeque.o linkedDequeMain.o

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all : arrayqueue linkeddeque

arrayqueue : $(ARRAY_OBJS)
	@ echo "$(BLUE)Array Queue Object File Created$(RESET)"
	@ $(CC) $(ARRAY_OBJS) -o $(ARRAY_QUEUE)
	@ echo "$(RED)Array Qeueu Created$(RESET)"

linkeddeque : $(LINKED_OBJS)
	@ echo "$(BLUE)Linked Deque Object File Created$(RESET)"
	@ $(CC) $(LINKED_OBJS) -o $(LINKED_DEQUEUE)
	@ echo "$(RED)Linked Deque Created$(RESET)"

%.o : %.c
	@ $(CC) -c $< -o $@

clean :
	@ rm -f $(ARRAY_OBJS) $(LINKED_OBJS)
	@ echo "$(RED)Object File Removed$(RESET)"

fclean : clean
	@ rm -f $(ARRAY_QUEUE) $(LINKED_DEQUEUE)
	@ echo "$(RED)Array Queue Removed$(RESET)"
	@ echo "$(RED)Linked Deque Removed$(RESET)"

re : fclean all
