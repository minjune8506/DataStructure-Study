#ifndef _BIN_TREE_
#define _BIN_TREE_

typedef struct BinTreeNodeType
{
	char data;
	int visited;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTreeNode* createNewNodeBT(BinTreeNode element);
BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void preorderTraversalBinTree(BinTree *pBinTree, BinTreeNode *curr, void (*func)(BinTreeNode *));
void postorderTraversalBinTree(BinTree *pBinTree, BinTreeNode *curr, void (*func)(BinTreeNode *));
void inorderTraversalBinTree(BinTree *pBinTree, BinTreeNode *curr, void (*func)(BinTreeNode *));
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);
BinTreeNode makeTreeNode(char data);
void printData(BinTreeNode *node);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
