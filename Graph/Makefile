CC = gcc
AG = arraygraph
AG_OBJS = arraygraph.o arrayGraphMain.o dijkstra.o floydWarshall.o
LG = linkedgraph
LG_OBJS = linkedgraph.o linkedGraphMain.o linkedlist.o graphTraverse.o kruskal.o

STACK_DIR = ../Stack/
QUEUE_DIR = ../Queue/
CFLAGS = -I$(STACK_DIR) -I$(QUEUE_DIR) -g

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all : arraygraph linkedgraph

arraygraph : $(AG_OBJS)
	@ echo "$(BLUE)Array Graph Object File Created$(RESET)"
	@ $(CC) -o $(AG) $(AG_OBJS)
	@ echo "$(RED)Array Graph Created$(RESET)"

linkedgraph : subdirectory $(LG_OBJS)
	@ echo "$(BLUE)Linked Graph Object File Created$(RESET)"
	@ $(CC) -o $(LG) $(LG_OBJS) $(STACK_DIR)linkedstack.o $(QUEUE_DIR)linkeddeque.o
	@ echo "$(RED)Linked Graph Created$(RESET)"

subdirectory :
	@ $(MAKE) -C $(STACK_DIR)
	@ $(MAKE) -C $(QUEUE_DIR)

%.o : %.c
	@ $(CC) -c $< -o $@ $(CFLAGS)

clean :
	@ $(MAKE) -C $(STACK_DIR) clean
	@ $(MAKE) -C $(QUEUE_DIR) clean
	@ rm -f $(AG_OBJS) $(LG_OBJS)
	@ echo "$(RED)Object File Removed$(RESET)"

fclean : clean
	@ $(MAKE) -C $(STACK_DIR) fclean
	@ $(MAKE) -C $(QUEUE_DIR) fclean
	@ rm -f $(AG) $(LG)
	@ echo "$(RED)Array Graph Removed$(RESET)"
	@ echo "$(RED)Linked Graph Removed$(RESET)"

re : fclean all

.PHONY : clean fclean re all arraygraph linkedgraph
