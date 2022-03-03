#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	BinTreeNode rootNode;
	BinTreeNode *temp;
	BinTree *tree;

	rootNode = makeTreeNode('A');
	tree = makeBinTree(rootNode);

	temp = insertLeftChildNodeBT(getRootNodeBT(tree), makeTreeNode('B'));
	insertLeftChildNodeBT(insertRightChildNodeBT(temp, makeTreeNode('E')), makeTreeNode('J'));
	temp = insertLeftChildNodeBT(temp, makeTreeNode('D'));
	insertLeftChildNodeBT(temp, makeTreeNode('H'));
	insertRightChildNodeBT(temp, makeTreeNode('I'));
	
	temp = insertRightChildNodeBT(getRootNodeBT(tree), makeTreeNode('C'));
	temp = insertLeftChildNodeBT(temp, makeTreeNode('F'));
	insertRightChildNodeBT(temp, makeTreeNode('K'));
	temp = insertRightChildNodeBT(getRootNodeBT(tree)->pRightChild, makeTreeNode('G'));
	insertLeftChildNodeBT(temp, makeTreeNode('L'));
	insertRightChildNodeBT(temp, makeTreeNode('M'));
	
	preorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// postorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	/*
					A
			B				C
		D		E		F		G
	H	 I	   J		  K   L	   M
	*/
	printf("\n");
	deleteBinTree(tree);
	// system("leaks a.out");
}
