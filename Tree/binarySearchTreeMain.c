#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	BinTreeNode rootNode;
	BinTreeNode *temp;
	BinTreeNode key;
	BinTree *tree;

	rootNode = makeTreeNode(30);
	tree = makeBinTree(rootNode);

	key.pLeftChild=NULL;
	key.pRightChild=NULL;
	key.visited=FALSE;
	key.data = 40;
	insertBST(tree, key);
	key.data = 34;
	insertBST(tree, key);
	key.data = 46;
	insertBST(tree, key);
	key.data = 32;
	insertBST(tree, key);
	key.data = 20;
	insertBST(tree, key);
	key.data = 10;
	insertBST(tree, key);
	key.data = 24;
	insertBST(tree, key);
	key.data = 6;
	insertBST(tree, key);
	key.data = 14;
	insertBST(tree, key);
	key.data = 12;
	insertBST(tree, key);
	key.data = 22;
	insertBST(tree, key);
	
	// preorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// postorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	/*
					A 30
			B20			  	   C40
		D10		E24		    F34		G46
	H6	 I14	   J22	   32
	    12
	*/

	key.data = 34;
	temp = searchBST(tree, key);
	printf("key : %d\n", temp->data);
	temp = searchParentNode(tree, key);
	printf("Parent key : %d\n", temp->data);
	
	key.data = 34;
	deleteBST(tree, key);
	inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	printf("\n");
	key.data = 32;
	deleteBST(tree, key);
	inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	printf("\n");
	key.data = 20;
	deleteBST(tree, key);
	inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// key.data = 34;
	// deleteBST(tree, key);
	printf("\n");
	deleteBinTree(tree);
	// system("leaks a.out");
}
