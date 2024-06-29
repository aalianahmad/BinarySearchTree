#include<iostream>
#include"bst.h"
using namespace std;
int main()
{
	bst t;
	t.insert(10);
	t.insert(8);
	t.insert(21);
	t.insert(7);
	t.insert(27);
	t.insert(5);
	t.insert(4);
	t.insert(3);
	cout << "InOrder traversal " << endl;
	t.inOrder();
	cout << endl;
	if (t.search(1))
	{
		cout << "present ";
	}
	else
	{
		cout << " not found ";
	}

	return 0;
}