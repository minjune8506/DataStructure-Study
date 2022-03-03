CC = gcc

BST = binarySearchTree
BST_OBJS = binarySearchTree.o binarySearchTreeMain.o binaryTree.o

BT = binaryTree
BT_OBJS = binaryTree.o binaryTreeMain.o

MAX_HEAP = maxHeap
MAX_HEAP_OBJS = heap.o maxHeapMain.o

MIN_HEAP = minHeap
MIN_HEAP_OBJS = heap.o minHeapMain.o

RED = \033[2;31m
BLUE = \033[1;34m
RESET = \033[0m

all : binaryTree binarySearchTree maxHeap minHeap

binarySearchTree : $(BST_OBJS)
	@ echo "$(RED)binarySearchTree Object Files Created$(RESET)"
	@ $(CC) -o $(BST) $(BST_OBJS)
	@ echo "$(BLUE)binarySearchTree Created$(RESET)"

binaryTree : $(BT_OBJS)
	@ echo "$(RED)binaryTree Object Files Created$(RESET)"
	@ $(CC) -o $(BT) $(BT_OBJS)
	@ echo "$(BLUE)binaryTree Created$(RESET)"

maxHeap : $(MAX_HEAP_OBJS)
	@ echo "$(RED)maxHeap Object Files Created$(RESET)"
	@ $(CC) -o $(MAX_HEAP) $(MAX_HEAP_OBJS)
	@ echo "$(BLUE)maxHeap Created$(RESET)"

minHeap : $(MIN_HEAP_OBJS)
	@ echo "$(RED)minHeap Object Files Created$(RESET)"
	@ $(CC) -o $(MIN_HEAP) $(MIN_HEAP_OBJS)
	@ echo "$(BLUE)minHeap Created$(RESET)"

%.o : %.c
	@ $(CC) -c $< -o $@

clean :
	@ rm -f $(BST_OBJS) $(BT_OBJS) $(MAX_HEAP_OBJS) $(MIN_HEAP_OBJS)
	@ echo "$(RED)Object Files Removed$(RESET)"

fclean : clean
	@ rm -f $(BST) $(BT) $(MAX_HEAP) $(MIN_HEAP)
	@ echo "$(RED)Executable Files Removed$(RESET)"

re : fclean all
