#include "BinarySearchTree.h"

int main()
{
	int elemToDelete = 7;

	//std::cout << "Element to delete \n"; std::cin >> elemToDelete; 

	BinarySearchTree binaryTree;
	binaryTree.AddElement(7);
	binaryTree.AddElement(3);
	binaryTree.AddElement(8);
	
#if 0
	binaryTree.AddElement(3);
	binaryTree.AddElement(1);
	binaryTree.AddElement(4);
	binaryTree.AddElement(5);
	binaryTree.AddElement(6);

	binaryTree.AddElement(12);
	binaryTree.AddElement(11);
	binaryTree.AddElement(8);
	binaryTree.AddElement(10);
	binaryTree.AddElement(17);
	binaryTree.AddElement(15);
	binaryTree.AddElement(20);
	std::cout << binaryTree.SearchElement(5) << "\n";
	std::cout << binaryTree.SearchElement(2) << "\n";
	std::cout << binaryTree.SearchElement(10) << "\n";
#endif
	binaryTree.PrintBinaryTree();
	std::cout << "\n";
	binaryTree.DeleteElement(elemToDelete);
	binaryTree.PrintBinaryTree();
}