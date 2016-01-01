/*
 * BLT.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: aconstan
 */

#include "BLT.h"

using namespace std;

BST::BST()
{
	root = NULL;
	found = false;
	//success = false;
	end = 0;

}

BST::~BST()
{
	clear();
}

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface * BST::getRootNode()
{
	return root;
}

/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool BST::add(int data)
{
	found = false;
	duplicate(root, data);

	if (found == true)
	{
		return false;
	}
	else
	{
		root = addNode(root, data);
		return true;
		/*if (success == true)
		{

			return true;
		}
		else
		{
			return false;
		}*/
	}
	return found;
}

/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool BST::remove(int data)
{
	found = false;
	duplicate(root, data);

	if (found == false)
	{
		return false;
	}
	else
	{
		root = removeNode(root, data);
		return true;
	}
	return found;
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void BST::clear()
{
	while (root != NULL)
	{
		remove(root->data);
	}
	found = false;
	end = 0;

	return;
}

//================================================================================

void BST::duplicate(Node* a, int data)
{

	if (a == NULL)
	{
		found = false;
		return;
	}
	else if (a->data == data)
	{
		found = true;
		return;
	}
	else if (data < a->data)
	{
		duplicate(a->left, data);
		return;
	}
	else if (data > a->data)
	{
		duplicate(a->right, data);
		return;
	}
}

Node * BST::addNode(Node* a, int data)
{
	//cout << "add" << endl;
	//cout << "this is the node being created :" << data << endl;
	if (a == NULL)
	{
		//success = true;
		//cout << a->data << endl;
		return new Node (data, NULL, NULL);
	}
	else if (data < a->data)
	{
		a->left = addNode(a->left, data);
		//cout << a->data << endl;
		return a;
	}
	else if (data > a->data)
	{
		a->right = addNode(a->right, data);
		//cout << a->data << endl;
		return a;
	}
	return a;
}

Node * BST::removeNode(Node* a, int data)
{
	//cout << "remove" << endl;
	if (a == NULL)
	{
		return a;
	}
	else if (a->data == data)
	{
		if (a->left == NULL)
		{
			Node* n = a->right;
			//cout << "This is if the left is NULL :" <<  a->data << endl;
			delete a;
			return n;
		}
		else if (a->left != NULL)
		{
			a->left = findEnd(a->left);
			a->data = end;
			//cout << "This is if the left is != NULL :" << a->data << endl;
			return a;

		}
	}
	else if (data < a->data)
	{
		a->left = removeNode(a->left, data);
		return a;
	}
	else if (data > a->data)
	{
		a->right = removeNode(a->right, data);
		return a;
	}
	return a;
}

Node * BST::findEnd(Node * b)
{
	if (b->right == NULL)
	{
		Node* left = b->left;
		end = b->data;
		delete b;
		return left;
	}
	else
	{
		b->right = findEnd(b->right);
		return b;
	}


}

