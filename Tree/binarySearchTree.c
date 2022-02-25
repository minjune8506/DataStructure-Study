#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

BinTreeNode *insertBST(BinTree *BST, BinTreeNode element)
{
	BinTreeNode *newNode;
	BinTreeNode *parent;

	if (searchBST(BST, element))
		return (0);
	newNode = createNewNodeBT(element);
	if (!getRootNodeBT(BST))
	{
		BST->pRootNode = newNode;
		return (BST->pRootNode);
	}
	parent = searchParentNode(BST, element);
	if (parent->data < element.data)
	{
		parent->pRightChild = newNode;
		return (parent->pRightChild);
	}
	else
	{
		parent->pLeftChild = newNode;
		return (parent->pLeftChild);
	}
}

BinTreeNode *searchBST(BinTree *BST, BinTreeNode key)
{
	BinTreeNode *result = getRootNodeBT(BST);
	while (result)
	{
		if (key.data == result->data)
			break ;
		else if (key.data < result->data)
			result = result->pLeftChild;
		else
			result = result->pRightChild;
	}
	return (result);
}

BinTreeNode *searchParentNode(BinTree *BST, BinTreeNode key)
{
	BinTreeNode *result = getRootNodeBT(BST);
	BinTreeNode *parent = NULL;
	
	while (result)
	{
		if (key.data == result->data)
			break ;
		parent = result;
		if (key.data < result->data)
			result  = result->pLeftChild;
		else
			result = result->pRightChild;
	}
	if (result == parent)
		return (NULL);
	return (parent);
}

BinTreeNode *findSuccNode(BinTreeNode *node)
{
	BinTreeNode *pPredecessor;

	pPredecessor = node->pLeftChild;
	while (pPredecessor->pRightChild)
		pPredecessor = pPredecessor->pRightChild;
	return (pPredecessor);
}

void deleteBST(BinTree *BST, BinTreeNode key)
{
	BinTreeNode *searched;
	BinTreeNode *parent;
	BinTreeNode *successor;
	BinTreeNode *parent_successor;
	
	searched = searchBST(BST, key);
	if (!searched)
	{
		fprintf(stderr, "key not exist\n");
		return ;
	}
	parent = searchParentNode(BST, key);
	if (!parent)
	{
		BST->pRootNode = NULL;
		deleteBinTreeNode(searched);
	}
	if (searched->pLeftChild && searched->pRightChild)
	{
		successor = findSuccNode(searched);
		parent_successor = searchParentNode(BST, *successor);
		if (parent->pLeftChild == searched)
			parent->pLeftChild->data = successor->data;
		else
			parent->pRightChild->data = successor->data;
		if (parent_successor->pLeftChild == successor)
			parent_successor->pLeftChild = successor->pLeftChild;
		else
			parent_successor->pRightChild = successor->pLeftChild;
		deleteBinTreeNode(successor);
	}
	else if (searched->pRightChild || searched->pLeftChild)
	{
		if (searched->pRightChild)
		{
			if (parent->pLeftChild == searched)
				parent->pLeftChild = searched->pRightChild;
			else
				parent->pRightChild = searched->pRightChild;
			searched->pRightChild = NULL;
		}
		else
		{
			if (parent->pLeftChild == searched)
				parent->pLeftChild = searched->pLeftChild;
			else
				parent->pRightChild = searched->pLeftChild;
			searched->pLeftChild = NULL;
		}
		deleteBinTreeNode(searched);
	}
	else
	{
		if (parent->pLeftChild == searched)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
		deleteBinTreeNode(searched);
	}
}

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
