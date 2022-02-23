#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

BinTreeNode *insertBST(BinTree *BST, BinTreeNode element)
{
	// BinTreeNode *result;
	BinTreeNode *newNode;
	BinTreeNode *parent;

	if (searchBST(BST, element))
		return (0);
	newNode = createNewNodeBT(element);
	if (!getRootNodeBT(BST))
		BST->pRootNode = newNode;
	// result = BST->pRootNode;
	// while (result)
	// {
	// 	if (result->data < element.data)
	// 		result = result->pRightChild;
	// 	else if (result->data > element.data)
	// 		result = result->pLeftChild;
	// }
	// result = newNode;
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
			result  = result->pLeftChild;
		else
			result = result->pRightChild;
	}
	return (result);
}

BinTreeNode *searchParentNode(BinTree *BST, BinTreeNode key)
{
	BinTreeNode *result = getRootNodeBT(BST);
	BinTreeNode *parent;
	
	while (result)
	{
		if (key.data == result->data)
			break ;
		else if (key.data < result->data)
		{
			parent = result;
			result  = result->pLeftChild;
		}
		else
		{
			parent = result;
			result = result->pRightChild;
		}
	}
	if (result == parent)
		return (NULL);
	return (parent);
}

BinTreeNode *findSuccNode(BinTreeNode *node)
{
	BinTreeNode *pPredecessor;

	pPredecessor = node->pLeftChild;
	while (pPredecessor)
		pPredecessor = pPredecessor->pRightChild;
	return (pPredecessor);
}

void deleteBST(BinTree *BST, BinTreeNode key)
{
	BinTreeNode *searched;
	BinTreeNode *parent;
	BinTreeNode *successor;
	BinTreeNode *parent_successor;
	
	parent = searchParentNode(BST, key);
	searched = searchBST(BST,key);
	if (!parent)
		BST->pRootNode = NULL;
	if (searched->pLeftChild && searched->pRightChild)
	{
		successor = findSuccNode(searched);
		parent_successor = searchParentNode(BST, *successor);
		if (parent->pLeftChild == searched)
			parent->pLeftChild = successor;
		else
			parent->pRightChild = successor;
		if (parent_successor->pLeftChild == successor)
			parent_successor->pLeftChild = NULL;
		else
			parent_successor->pRightChild = NULL;
	}
	else if (searched->pRightChild || searched->pLeftChild)
	{
		if (searched->pRightChild)
		{
			if (parent->pLeftChild == searched)
				parent->pLeftChild = searched->pRightChild;
			else
				parent->pRightChild = searched->pRightChild;
		}
		else
		{
			if (parent->pLeftChild == searched)
				parent->pLeftChild = searched->pLeftChild;
			else
				parent->pRightChild = searched->pLeftChild;
			// searched->pLeftChild = NULL; //내일 ><
		}
	}
	else
	{
		if (parent->pLeftChild == searched)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
	}
	// deleteBinTreeNode(searched);
	free(searched);
}

int main(void)
{
	BinTreeNode rootNode;
	BinTreeNode *temp;
	BinTreeNode key;
	BinTree *tree;

	rootNode = makeTreeNode(30);
	tree = makeBinTree(rootNode);

	temp = insertLeftChildNodeBT(getRootNodeBT(tree), makeTreeNode(20));
	insertLeftChildNodeBT(insertRightChildNodeBT(temp, makeTreeNode(24)), makeTreeNode(22));
	temp = insertLeftChildNodeBT(temp, makeTreeNode(10));
	insertLeftChildNodeBT(temp, makeTreeNode(6));
	insertRightChildNodeBT(temp, makeTreeNode(14));
	
	temp = insertRightChildNodeBT(getRootNodeBT(tree), makeTreeNode(40));
	temp = insertLeftChildNodeBT(temp, makeTreeNode(34));
	temp = insertRightChildNodeBT(getRootNodeBT(tree)->pRightChild, makeTreeNode(46));
	
	// preorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// postorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	/*
					A 30
			B20			  	   C40
		D10		E24		    F34		G46
	H6	 I14	   J22	   32
	*/
	key.data = 34;
	temp = searchBST(tree, key);
	printf("key : %d\n", temp->data);
	temp = searchParentNode(tree, key);
	printf("Parent key : %d\n", temp->data);
	key.data = 32;
	insertBST(tree, key);
	
	key.data = 34;
	deleteBST(tree, key);
	inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	key.data = 32;
	deleteBST(tree, key);
	inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// key.data = 20;
	// deleteBST(tree, key);
	// inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
	// deleteBinTree(tree);
	// system("leaks a.out");
}
