#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int NOT_SET = -1000;

struct Node 
{
	int m_nVal;
	struct Node* m_pLeftChild;
	struct Node* m_pRightChild;
} Node_Default = { -999, NULL, NULL} ;

typedef struct Node Node;

void Insert(Node** pRoot, int nVal);
void TraverseInOrder(Node* pRoot);
void TraversePreOrder(Node* pRoot);
void TraversePostOrder(Node* pRoot);
int CheckHeight(Node* pRoot);
int GetHeight(Node* pRoot);
bool IsBalanced(Node* pRoot);
