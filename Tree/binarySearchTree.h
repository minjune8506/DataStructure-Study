#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

#include "binaryTree.h"

BinTreeNode *searchBST(BinTree *BST, BinTreeNode key);
BinTreeNode *insertBST(BinTree *BST, BinTreeNode element);
void deleteBST(BinTree *BST, BinTreeNode key);
BinTreeNode *searchParentNode(BinTree *BST, BinTreeNode key);
BinTreeNode *findSuccNode(BinTreeNode *node);
#endif
