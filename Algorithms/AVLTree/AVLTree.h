#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <stdlib.h>

template <typename T>
struct AVLNode
{
	AVLNode(T val) : m_data(val), m_nHeight(0), pLeft(nullptr), pRight(nullptr){}
	
	int Height() { return m_nHeight; }
	void SetHeight(int val) { m_nHeight = val; }

	T m_data;
	int m_nHeight;
	struct AVLNode* pLeft;
	struct AVLNode* pRight;
};

template <typename T>
class AVLTree
{
public:
	AVLTree() : m_pRoot(nullptr){}
	void PrintInOrder();
	void AddNode(T val);

	int GetHeight(const AVLNode<T>* pRoot);
	AVLNode<T>* GetNode(T val);
	int GetChildHeightDiff(const AVLNode<T>*& pRoot);

	void AdjustHeight(AVLNode<T>*& pRoot);

	AVLNode<T>* LeftLeftRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* RightRightRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* RightLeftRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* LeftRightRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* Balance(AVLNode<T>*& pRoot);

private:
	void PrintInOrderHelper(const AVLNode<T>* pRoot);
	AVLNode<T>* AddNodeHelper(T val, AVLNode<T>*& pRoot);

	AVLNode<T>* GetNodeHelper(T val, AVLNode<T>*& pRoot);

	
	

	AVLNode<T>* m_pRoot;
};

template <typename T>
void AVLTree<T>::PrintInOrder()
{
	PrintInOrderHelper(m_pRoot);
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
int AVLTree<T>::GetHeight(const AVLNode<T>* pRoot)
{
	if(pRoot == nullptr)
		return 0;

	int nLeftHeight = GetHeight(pRoot->pLeft);
	int nRightHeight = GetHeight(pRoot->pRight);

	int maxHeight = nLeftHeight < nRightHeight ? nRightHeight : nLeftHeight;

	return maxHeight + 1;
}

template <typename T>
AVLNode<T>* AVLTree<T>::GetNode(T val)
{
	return GetNodeHelper(val, m_pRoot);
}

template <typename T>
int AVLTree<T>::GetChildHeightDiff(const AVLNode<T>*& pRoot)
{
	if(pRoot == nullptr)
		return 0;

	int nLeftHeight = 0;
	int nRightHeight = 0;
	if(pRoot->pRight)
		nRightHeight = pRoot->pRight->Height();

	if(pRoot->pLeft)
		nLeftHeight = pRoot->pLeft->Height();

	return nLeftHeight - nRightHeight;
}

template <typename T>
void AVLTree<T>::AdjustHeight(AVLNode<T>*& pRoot)
{
	int nLeftHeight = 0;
	int nRightHeight = 0;
	
	if(pRoot->pLeft)
		nLeftHeight = pRoot->pLeft->Height();

	if(pRoot->pRight)
		nRightHeight = pRoot->pRight->Height();

	pRoot->SetHeight(std::max(nLeftHeight, nRightHeight) + 1);
}

template <typename T>
void AVLTree<T>::PrintInOrderHelper(const AVLNode<T>* pRoot)
{
	if(pRoot != NULL)
	{
		std::cout << pRoot->m_data << "\n";
		PrintInOrderHelper(pRoot->pLeft);
		PrintInOrderHelper(pRoot->pRight);
	}
}

template <typename T>
AVLNode<T>* AVLTree<T>::AddNodeHelper(T val, AVLNode<T>*& pRoot)
{
	if(pRoot == nullptr)
		return new AVLNode<T>(val);

	if(val > pRoot->m_data)
	{
		pRoot->pRight = AddNodeHelper(val, pRoot->pRight);
	}
	else
	{
		pRoot->pLeft = AddNodeHelper(val, pRoot->pLeft);
	}

	AdjustHeight(pRoot);
	Balance(pRoot);
}

template <typename T>
AVLNode<T>* AVLTree<T>::GetNodeHelper(T val, AVLNode<T>*& pRoot)
{
	if(pRoot != nullptr)
	{
		if(pRoot->m_data == val)
			return pRoot;
		else
		{
			if(val > pRoot->m_data)
				return GetNodeHelper(val, pRoot->pRight);
			else
				return GetNodeHelper(val, pRoot->pLeft);
		}
	}
	else
		return nullptr;
}

template <typename T>
AVLNode<T>* AVLTree<T>::LeftLeftRotation(AVLNode<T>*& pRoot)
{
	AVLNode<T>* newRoot = pRoot->pRight;
	pRoot->pRight = newRoot->pLeft;
	newRoot->pLeft = pRoot;

	if(pRoot == m_pRoot)
		m_pRoot = newRoot;
	else
		pRoot = newRoot;

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

	const AVLNode<T>* temp = pRoot;

	int nDiff = GetChildHeightDiff(temp);
	
	// no changs
	if(abs(nDiff) == 1 || abs(nDiff) == 0)
		return pRoot;

	// left subtree has bigger height 
	if(nDiff > 1)
	{
		std::cout << "balancing root node with val" << pRoot->m_data << "\n";
		temp = pRoot->pLeft;
		if(GetChildHeightDiff(temp) > 0)
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
		temp = pRoot->pRight;
		if(GetChildHeightDiff(temp) < 0)
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

#endif