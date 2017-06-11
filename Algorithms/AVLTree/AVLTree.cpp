#include "AVLTree.h"




int main()
{
	AVLTree<int> avlTree;

	avlTree.AddNode(1);
	avlTree.AddNode(2);
	avlTree.AddNode(3);
	avlTree.AddNode(7);
	avlTree.AddNode(6);
	avlTree.RemoveNode(1);
#if 0
	avlTree.AddNode(100);
	avlTree.AddNode(15);
	avlTree.AddNode(7);
	avlTree.AddNode(6);
	avlTree.AddNode(10);
	avlTree.AddNode(9);
	avlTree.AddNode(13);
	avlTree.AddNode(12);

	avlTree.RemoveNode(15);
#endif
	avlTree.PrintInOrder();

#if 0
	AVLNode<int>* pNode = avlTree.GetNode(1);
	std::cout << "Value of node = " << pNode->m_data << " and height = " << avlTree.GetHeight(pNode) << "\n";

	pNode = avlTree.GetNode(2);
	std::cout << "Value of node = " << pNode->m_data << " and height = " << avlTree.GetHeight(pNode) << "\n";

	pNode = avlTree.GetNode(3);
	std::cout << "Value of node = " << pNode->m_data << " and height = " << avlTree.GetHeight(pNode) << "\n";

	pNode = avlTree.GetNode(7);
	std::cout << "Value of node = " << pNode->m_data << " and height = " << avlTree.GetHeight(pNode) << "\n";

	pNode = avlTree.GetNode(6);
	std::cout << "Value of node = " << pNode->m_data << " and height = " << avlTree.GetHeight(pNode) << "\n";
#endif

	//avlTree.LeftRightRotation(pNode);

	//avlTree.PrintInOrder();
	//
	//std::cout << "Value of node = " << pNode->m_data << " and height = " << avlTree.GetHeight(pNode) << "\n";

	//std::cout << "Children height diff for node " << pNode->m_data << " is " << avlTree.GetChildHeightDiff(pNode) << "\n";
	return 0;
}