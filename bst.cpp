#include "bst.h"
#include<iostream>
using namespace std;
void bst::inOrderTraversal(node* n)
{
	if (n == nullptr)
	{
		return;
	}
	inOrderTraversal(n->left);
	cout << n->data << " ";
	inOrderTraversal(n->right);
}
void bst::deleteNode(int data, node*& nodePtr)
{
	if (data < nodePtr->data)
	{
		deleteNode(data, nodePtr->left);
	}
	else if (data > nodePtr->data)
	{
		deleteNode(data, nodePtr->right);
	}
	else
		makeDeletion(nodePtr);

}
void bst::makeDeletion(node*&nodePtr)
{
	// temporary node
	node* temp;
	if (nodePtr == nullptr)
	{
		cout << "Can not delete empty node ";
	}
	else if (nodePtr->left!= nullptr&& nodePtr->right == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->left;
		delete temp;
	}
	else if (nodePtr->left == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->right;
		delete temp;
	}
	else
	{
		temp = nodePtr->right;
		while (temp->left)
		{
			temp = temp->left;
		}
		temp->left = nodePtr->left;
		temp = nodePtr;
		nodePtr = nodePtr->right;
		delete temp;
	}
}
bst::bst(): root(nullptr){}
void bst::insert(int d)
{
	node* temp = nullptr;
	node* newNode = new node(d);
	// check root
	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		temp = root;
		while (temp != nullptr)
		{
			if (d < temp->data)
			{
				if (temp->left)
				{
					temp = temp->left;
				}
				else
				{
					temp->left = newNode;
					break;
				}
			}
			else if (d > temp->data)
			{
				if (temp->right)
				{
					temp = temp->right;
				}
				else
				{
					temp->right = newNode;
					break;
				}
			}
			else
			{
				cout << "Duplicate ";
				break;
			}
		}
	}

}
bool bst::search(int d)
{ 
	node* temp = root;
	while (temp != nullptr)
	{
		if (temp->data == d)
		{
			return true;
		}
		else if (temp->data > d)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return false;
}
void bst::inOrder()
{
	inOrderTraversal(root);
	cout << endl;
}

void bst::remove(int data)
{
	deleteNode(data, root);
}
