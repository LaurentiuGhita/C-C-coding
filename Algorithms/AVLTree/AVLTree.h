#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <stdlib.h>

template <typename T>
struct AVLNode
{
	AVLNode(T val) : m_data(val), m_nHeight(1), pLeft(nullptr), pRight(nullptr), pParent(nullptr){}
	T m_data;
	int m_nHeight;
	struct AVLNode* pLeft;
	struct AVLNode* pRight;
	struct AVLNode* pParent;

	int Height() { return m_nHeight; } const
	void SetHeight(int nHeight) { m_nHeight = nHeight; }
};

template <typename T>
class AVLTree
{
public:
	AVLTree() : m_pRoot(nullptr){}
	void PrintInOrder();
	void AddNode(T val);

	int GetHeight(AVLNode<T>& root);
	AVLNode<T>& GetNode(T val);
	int GetChildHeightDiff(AVLNode<T>& root);

	AVLNode<T>* LeftLeftRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* RightRightRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* RightLeftRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* LeftRightRotation(AVLNode<T>*& pRoot);
	

	AVLNode<T>* Balance(AVLNode<T>*& pRoot);
	int	AdjustHeight(AVLNode<T>& pRoot);
	int RecomputeHeight(AVLNode<T>& pRoot);

private:
	void PrintInOrderHelper(const AVLNode<T>& pRoot);
	AVLNode<T>* AddNodeHelper(T val, AVLNode<T>*& pRoot);

	AVLNode<T>& GetNodeHelper(T val, AVLNode<T>& root);

	
	

	AVLNode<T>* m_pRoot;
};

template <typename T>
void AVLTree<T>::PrintInOrder()
{
	PrintInOrderHelper(*m_pRoot);
}

template <typename T>
void AVLTree<T>::AddNode(T val)
{
	if(m_pRoot == nullptr)
	{
		m_pRoot = new AVLNode<T>(val);
	}
	else
		AddNodeHelper(val, m_pRoot);
}

template <typename T>
int AVLTree<T>::GetHeight(AVLNode<T>& root)
{
	return root.Height();
}

template <typename T>
AVLNode<T>& AVLTree<T>::GetNode(T val)
{
	return GetNodeHelper(val, *m_pRoot);
}

template <typename T>
int AVLTree<T>::GetChildHeightDiff(AVLNode<T>& root)
{
	int nLeftHeight = 0;
	int nRightHeight = 0;
	
	if(root.pLeft)
		nLeftHeight = GetHeight(*root.pLeft);
	if(root.pRight) 
		nRightHeight = GetHeight(*root.pRight);

	return nLeftHeight - nRightHeight;
}

template <typename T>
void AVLTree<T>::PrintInOrderHelper(const AVLNode<T>& root)
{
	std::cout << root.m_data << " weight " << root.m_nHeight << " ";
	if(root.pParent)
		std::cout << " with parent " << root.pParent->m_data;
	
	if(root.pLeft)
		std::cout << " with left child " << root.pLeft->m_data;

	if(root.pRight)
		std::cout << " and right child " << root.pRight->m_data;

	std::cout << "\n";

	if(root.pLeft)
	{
		PrintInOrderHelper(*root.pLeft);
	}
	
	if(root.pRight)
		PrintInOrderHelper(*root.pRight);
}

template <typename T>
AVLNode<T>* AVLTree<T>::AddNodeHelper(T val, AVLNode<T>*& pRoot)
{
	if(pRoot == nullptr)
		return new AVLNode<T>(val);

	// add as left child
	if(val > pRoot->m_data)
	{
		pRoot->pRight = AddNodeHelper(val, pRoot->pRight);
		pRoot->pRight->pParent = pRoot;
	}
	else if(val < pRoot->m_data)
	{
		pRoot->pLeft = AddNodeHelper(val, pRoot->pLeft);
		pRoot->pLeft->pParent = pRoot;
	}


	AdjustHeight(*pRoot);
	Balance(pRoot);
	return pRoot;
//	
}

template <typename T>
AVLNode<T>& AVLTree<T>::GetNodeHelper(T val, AVLNode<T>& root)
{
	if(root.m_data == val)
		return root;
	else
	{
		if(val > root.m_data)
			return GetNodeHelper(val, *root.pRight);
		else
			return GetNodeHelper(val, *root.pLeft);
	}
}

template <typename T>
AVLNode<T>* AVLTree<T>::LeftLeftRotation(AVLNode<T>*& pRoot)
{
	AVLNode<T>* newRoot = pRoot->pRight;
	newRoot->pParent = pRoot->pParent;


	pRoot->pRight = newRoot->pLeft;
	if(newRoot->pLeft)
		newRoot->pLeft->pParent = pRoot;

	newRoot->pLeft = pRoot;
	pRoot->pParent = newRoot;

	if(pRoot == m_pRoot)
		m_pRoot = newRoot;
	else
		pRoot = newRoot;

	RecomputeHeight(*newRoot);

	return newRoot;
}

template <typename T>
AVLNode<T>* AVLTree<T>::RightRightRotation(AVLNode<T>*& pRoot)
{
	AVLNode<T>* newRoot = pRoot->pLeft;
	pRoot->pLeft = newRoot->pRight;
	newRoot->pRight = pRoot;

	if(pRoot == m_pRoot)
		m_pRoot = newRoot;
	else
		pRoot = newRoot;

	RecomputeHeight(*newRoot);
	return newRoot;
}


template <typename T>
AVLNode<T>* AVLTree<T>::RightLeftRotation(AVLNode<T>*& pRoot)
{
	bool bChangeRoot = false;
	/* first rotate left left subtree */
	AVLNode<T>* temp = pRoot->pLeft;
	pRoot->pLeft = LeftLeftRotation(temp);

	if(pRoot == m_pRoot)
		bChangeRoot = true;

	AVLNode<T>* newRoot = RightRightRotation(pRoot);

	if(bChangeRoot)
		m_pRoot = newRoot;

	return newRoot;
}

template <typename T>
AVLNode<T>* AVLTree<T>::LeftRightRotation(AVLNode<T>*& pRoot)
{
	bool bChangeRoot = false;
	/* first rotate right the right subtree */
	AVLNode<T>* temp = pRoot->pRight;
	pRoot->pRight = RightRightRotation(temp);

	if(pRoot == m_pRoot)
		bChangeRoot = true;

	AVLNode<T>* newRoot = LeftLeftRotation(pRoot);

	if(bChangeRoot)
		m_pRoot = newRoot;

	return newRoot;
}


template <typename T>
AVLNode<T>* AVLTree<T>::Balance(AVLNode<T>*& pRoot)
{
	if(pRoot == nullptr)
		return nullptr;

	bool bChangeRoot = false;
	if(pRoot == m_pRoot)
		bChangeRoot = true;

	AVLNode<T>& temp = *pRoot;

	int nDiff = GetChildHeightDiff(temp);
	
	// no changs
	if(abs(nDiff) == 1 || abs(nDiff) == 0)
		return pRoot;

	// left subtree has bigger height 
	if(nDiff > 1)
	{
		std::cout << "balancing root node with val" << pRoot->m_data << "\n";
		if(GetChildHeightDiff(*(pRoot->pLeft)) > 0)
		{
			// simple left left
			pRoot = RightRightRotation(pRoot);

		}
		else
		{
			pRoot = RightLeftRotation(pRoot);
		}
	}
	else
	{	
		if(GetChildHeightDiff(*(pRoot->pRight)) < 0)
		{
			// simple right right
			pRoot = LeftLeftRotation(pRoot);
		}
		else
			pRoot = LeftRightRotation(pRoot);
	}

	if(bChangeRoot)
		m_pRoot = pRoot;

	return pRoot;
}

template <typename T>
int	AVLTree<T>::AdjustHeight(AVLNode<T>& root)
{
	int nLeft = 0;
	int nRight = 0;

	if(root.pLeft)
		nLeft = GetHeight(*root.pLeft);
	
	if(root.pRight)
		nRight = GetHeight(*root.pRight);

	int max = std::max(nLeft, nRight);

	root.SetHeight(max + 1);
	return max + 1;
}

template <typename T>
int AVLTree<T>::RecomputeHeight(AVLNode<T>& root)
{
	if(nullptr == root.pRight && nullptr == root.pLeft)
	{
		root.SetHeight(1);
		return 1;
	}

	int nLeftHeight = 0;
	if(root.pLeft)
		nLeftHeight = RecomputeHeight(*root.pLeft);

	int nRightHeight = 0;
	if(root.pRight)
		nRightHeight = RecomputeHeight(*root.pRight);

	int max = std::max(nLeftHeight, nRightHeight);
	root.SetHeight(max + 1);

}


#endif