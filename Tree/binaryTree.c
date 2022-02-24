#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * createNewNodeBT() - Create New Binary Tree Node
 * 
 * return : Pointer of New Binary Tree Node or NULL
 * element : Binary Tree Node element
 */
BinTreeNode* createNewNodeBT(BinTreeNode element)
{
	BinTreeNode *newNode;
	
	newNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!newNode)
		return (NULL);
	*newNode = element;
	return (newNode);
}

/**
 * makeBinTree() - Binary Tree 생성
 * 
 * return : Binary Tree의 주소 or NULL
 * rootNode : Binary Tree의 Root Node
 */
BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *pBinTree;

	pBinTree = (BinTree *)malloc(sizeof(BinTree));
	if (!pBinTree)
		return (NULL);
	pBinTree->pRootNode = createNewNodeBT(rootNode);
	if (!pBinTree->pRootNode)
		return (NULL);
	return (pBinTree);
}

/**
 * getRootNodeBT() - Binary Tree의 Root Node 반환
 * 
 * return : Binary Tree의 Root Node의 포인터 or NULL
 * pBinTree : Binary Tree의 포인터
 */
BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree || !pBinTree->pRootNode)
		return (NULL);
	return (pBinTree->pRootNode);
}

/**
 * insertLeftChildNodeBT() - 왼쪽 자식 노드 추가
 *
 * return : 추가한 자식 노드의 주소 or NULL
 * pParentNode : 추가할 노드의 부모 노드
 * element : 추가할 노드
 */
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (!pParentNode || pParentNode->pLeftChild)
		return (NULL);
	pParentNode->pLeftChild = createNewNodeBT(element);
	if (!pParentNode->pLeftChild)
		return (NULL);
	return (pParentNode->pLeftChild);
}

/**
 * insertRightChildNodeBT() - 오른쪽 자식 노드 추가
 * 
 * return : 추가한 자식 노드의 주소 or NULL
 * pParentNode : 추가할 노드의 부모 노드
 * element : 추가할 노드
 */
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (!pParentNode || pParentNode->pRightChild)
		return (NULL);
	pParentNode->pRightChild = createNewNodeBT(element);
	if (!pParentNode->pRightChild)
		return (NULL);
	return (pParentNode->pRightChild);
}

/**
 * getLeftChildNodeBT() - pNode의 왼쪽 자식 노드 반환
 * 
 * return : pNode의 왼쪽 자식 노드의 주소 or NULL
 * pNode : Binary Tree Node의 주소
 */
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode || !pNode->pLeftChild)
		return (NULL);
	return (pNode->pLeftChild);
}

/**
 * getRightChildNodeBT() - pNode의 오른쪽 자식 노드 반환
 * 
 * return : pNode의 오른쪽 자식 노드의 주소 or NULL
 * pNode : Binary Tree Node의 주소
 */
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode || !pNode->pRightChild)
		return (NULL);
	return (pNode->pRightChild);
}

void printData(BinTreeNode *node)
{
	printf("%d -> ", node->data);
}

/**
 * preorderTraversalBinTree() - 이진 트리의 전위 순회
 * 
 * return : None
 * pBinTree : Binary Tree의 주소
 * curr : 현재 Binary Tree Node의 주소
 */
void preorderTraversalBinTree(BinTree *pBinTree, BinTreeNode *curr, void (*func)(BinTreeNode *))
{
	if (!pBinTree || !curr || curr->visited)
		return ;
	// curr->visited = TRUE;
	func(curr);
	preorderTraversalBinTree(pBinTree, curr->pLeftChild, func);
	preorderTraversalBinTree(pBinTree, curr->pRightChild, func);
}

/**
 * preorderTraversalBinTree() - 이진 트리의 중위 순회
 * 
 * return : None
 * pBinTree : Binary Tree의 주소
 * curr : 현재 Binary Tree Node의 주소
 */
void inorderTraversalBinTree(BinTree *pBinTree, BinTreeNode *curr, void (*func)(BinTreeNode *))
{
	if (!pBinTree || !curr || curr->visited)
		return ;
	// curr->visited = 1;
	inorderTraversalBinTree(pBinTree, curr->pLeftChild, func);
	func(curr);
	inorderTraversalBinTree(pBinTree, curr->pRightChild, func);
}

/**
 * postorderTraversalBinTree() - 이진 트리의 후위 순회
 * 
 * return : None
 * pBinTree : Binary Tree의 주소
 * curr : 현재 Binary Tree Node의 주소
 * func : 순회를 하며 각 노드에 적용할 함수
 */
void postorderTraversalBinTree(BinTree *pBinTree, BinTreeNode *curr, void (*func)(BinTreeNode *))
{
	if (!pBinTree || !curr || curr->visited)
		return ;
	// curr->visited = 1;
	postorderTraversalBinTree(pBinTree,curr->pLeftChild, func);
	postorderTraversalBinTree(pBinTree,curr->pRightChild, func);
	func(curr);
}

/**
 * deleteBinTree() - Binary Tree 삭제
 * 
 * return : None
 * pBinTree : Binary Tree의 주소
 */
void deleteBinTree(BinTree* pBinTree)
{
	postorderTraversalBinTree(pBinTree, getRootNodeBT(pBinTree), deleteBinTreeNode);
	free(pBinTree);
}

/**
 * deleteBinTreeNode() - Binary Tree Node 삭제
 * 
 * return : None
 * pNode : Binary Tree Node 주소
 */
void deleteBinTreeNode(BinTreeNode* pNode)
{
	pNode->data = 0;
	pNode->pLeftChild = 0;
	pNode->pRightChild = 0;
	pNode->visited = 0;
	free(pNode);
}

BinTreeNode makeTreeNode(char data)
{
	BinTreeNode node;
	
	node.data = data;
	node.pLeftChild = NULL;
	node.pRightChild = NULL;
	node.visited = FALSE;
	return (node);
}

// int main(void)
// {
// 	BinTreeNode rootNode;
// 	BinTreeNode *temp;
// 	BinTree *tree;

// 	rootNode = makeTreeNode('A');
// 	tree = makeBinTree(rootNode);

// 	temp = insertLeftChildNodeBT(getRootNodeBT(tree), makeTreeNode('B'));
// 	insertLeftChildNodeBT(insertRightChildNodeBT(temp, makeTreeNode('E')), makeTreeNode('J'));
// 	temp = insertLeftChildNodeBT(temp, makeTreeNode('D'));
// 	insertLeftChildNodeBT(temp, makeTreeNode('H'));
// 	insertRightChildNodeBT(temp, makeTreeNode('I'));
	
// 	temp = insertRightChildNodeBT(getRootNodeBT(tree), makeTreeNode('C'));
// 	temp = insertLeftChildNodeBT(temp, makeTreeNode('F'));
// 	insertRightChildNodeBT(temp, makeTreeNode('K'));
// 	temp = insertRightChildNodeBT(getRootNodeBT(tree)->pRightChild, makeTreeNode('G'));
// 	insertLeftChildNodeBT(temp, makeTreeNode('L'));
// 	insertRightChildNodeBT(temp, makeTreeNode('M'));
	
// 	preorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
// 	// inorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
// 	// postorderTraversalBinTree(tree, getRootNodeBT(tree), printData);
// 	/*
// 					A
// 			B				C
// 		D		E		F		G
// 	H	 I	   J		  K   L	   M
// 	*/
// 	printf("\n");
// 	deleteBinTree(tree);
// 	system("leaks a.out");
// }
