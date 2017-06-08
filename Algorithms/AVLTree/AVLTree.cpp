#include "AVLTree.h"




int main()
{
	AVLTree<int> avlTree;
	avlTree.AddNode(5);
	avlTree.AddNode(7);
	avlTree.AddNode(6);

	//AVLNode<int>* pNode = avlTree.GetNode(5);
	//avlTree.LeftRightRotation(pNode);

	avlTree.PrintInOrder();
	//
	//std::cout << "Value of node = " << pNode->m_data << " and height = " << avlTree.GetHeight(pNode) << "\n";

	//std::cout << "Children height diff for node " << pNode->m_data << " is " << avlTree.GetChildHeightDiff(pNode) << "\n";

}