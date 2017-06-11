#include "AVLTree.h"
#include <string>
#include <sstream>



int main()
{
	AVLTree<int> avlTree;

	std::string line;
	while(std::getline(std::cin, line))
	{
		std::stringstream ss;
		ss << line;
		std::string part1;

		ss >> part1;

		if(part1 == "add" || part1 == "Add" || part1 == "a")
		{
			int number;
			ss >> number;
			avlTree.AddNode(number);
		}

		if(part1 == "remove" || part1 == "delete" || part1 == "d" || part1 == "r")
		{
			int number;
			ss >> number;
			avlTree.RemoveNode(number);
		}

		if(part1 == "print" || part1 == "p")
		{
			avlTree.PrintInOrder();
		}

		if(part1 == "q" || part1 == "quit")
		{
			return 0;
		}

		std::cout << "-----------------------------------------------\n";
	}
#if 0
	avlTree.AddNode(1);
	avlTree.AddNode(2);
	avlTree.AddNode(3);
	avlTree.AddNode(7);
	avlTree.AddNode(6);
	avlTree.RemoveNode(1);

	avlTree.AddNode(100);
	avlTree.AddNode(15);
	avlTree.AddNode(7);
	avlTree.AddNode(6);
	avlTree.AddNode(10);
	avlTree.AddNode(9);
	avlTree.AddNode(13);
	avlTree.AddNode(12);

	avlTree.RemoveNode(15);

	avlTree.PrintInOrder();
#endif
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