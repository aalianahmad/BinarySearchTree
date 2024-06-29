#pragma once
#include"node.h"
class bst
{
	node* root;
	void inOrderTraversal(node*);
	void deleteNode(int, node*&);
	void makeDeletion(node*&);
public:
	bst();
	void insert(int);
	bool search(int );
	void inOrder();
	void remove(int);


};