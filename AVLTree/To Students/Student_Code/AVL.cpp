/*
 * AVL.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: aconstan
 */

#include "AVL.h"

using namespace std;

AVL::AVL()
{

	root = NULL;
	found = false;
	end = 0;


}

AVL::~AVL()
{
	clear();
}

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface * AVL::getRootNode()
{
	return root;
}

/*
 * Attempts to add the given int to the AVL tree
 * Rebalances the tree if data is successfully added
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool AVL::add(int data)
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
 * Attempts to remove the given int from the AVL tree
 * Rebalances the tree if data is successfully removed
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool AVL::remove(int data)
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
 * ROTATIONS:
 * 			LEFT
 *
 * 				IDENTIFY NODES TO ROTATE
 *
 * 				ROT.RIGHT=CUR.LEFT
 * 				CUR.LEFT=ROT
 * 				CUR=ROT
 *
 *
 *
 *
 * 			RIGHT
 *
 *
 *
 */

//=========================================================================

void AVL::clear()
{
	while (root != NULL)
	{
		remove(root->data);
	}
	found = false;
	end = 0;
	root = NULL;


	return;
}

//==========================================================================

void AVL::duplicate(Node* a, int data)
{

	if (a == NULL)
	{
		found = false;
		return;
	}
	else if (a->data == data)
	{
		found = true;

		int check = checkBalance(a);

		if (check != 0)
		{
			a = determineFxn(a, check);
		}

		return;
	}
	else if (data < a->data)
	{
		duplicate(a->left, data);

		int check = checkBalance(a);

		if (check != 0)
		{
			a = determineFxn(a, check);
		}

		return;
	}
	else if (data > a->data)
	{
		duplicate(a->right, data);

		int check = checkBalance(a);

		if (check != 0)
		{
			a = determineFxn(a, check);
		}

		return;
	}
}

Node * AVL::addNode(Node* a, int data)
{
	//cout << "add" << endl;
	//cout << "this is the node being created :" << data << endl;
	if (a == NULL)
	{
		//cout << data << " HAS BEEN ADDED" << endl;
		return new Node (data, NULL, NULL);
	}
	else if (data < a->data)
	{
		//cout << "GOING LEFT" << endl;
		a->left = addNode(a->left, data);

		//cout << "CHECKING BALANCE LEFT" << endl;
		int check = checkBalance(a);
		//cout << "Check\t" << check << endl;

		if (check != 0)
		{
			//cout << "HELLO" << endl;
			a = determineFxn(a, check);
		}


		//cout << "GOING UP" << endl;
		return a;
	}
	else if (data > a->data)
	{
		//cout << "GOING RIGHT" << endl;
		a->right = addNode(a->right, data);


		//cout << "CHECKING BALANCE RIGHT" << endl;
		int check = checkBalance(a);
		//cout << "Check\t" << check << endl;

		if (check != 0)
		{
			//cout << "HELLO" << endl;
			a = determineFxn(a, check);
		}


		//cout << "GOING UP" << endl;
		return a;
	}
	return a;
}

Node * AVL::removeNode(Node* a, int data)
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

			//cout << a << " HAS BEEN REMOVED" << endl;
			//cout << "I AM HERE" << endl;


			delete a;
			return n;
		}
		else if (a->left != NULL)
		{
			a->left = findEnd(a->left);
			a->data = end;

			//cout << "I AM A\t" << a->getData() << endl;
			//cout << "END\t=\t" << end << endl;

			int check = checkBalance(a);
			//cout << "Check\t" << check << endl;

			if (check != 0)
			{
				//cout << "HELLO" << endl;
				a = determineFxn(a, check);
			}

			return a;

		}
	}
	else if (data < a->data)
	{
		a->left = removeNode(a->left, data);

		int check = checkBalance(a);
		//cout << "Check\t" << check << endl;

		if (check != 0)
		{
			//cout << "HELLO" << endl;
			a = determineFxn(a, check);
		}

		return a;
	}
	else if (data > a->data)
	{
		a->right = removeNode(a->right, data);

		int check = checkBalance(a);
		//cout << "Check\t" << check << endl;

		if (check != 0)
		{
			//cout << "HELLO" << endl;
			a = determineFxn(a, check);
		}

		return a;
	}
	return a;
}

Node * AVL::findEnd(Node * b)
{
	if (b->right == NULL)
	{
		Node* left = b->left;
		end = b->data;

		//cout << "END\t=\t" << end << endl;

		delete b;
		return left;
	}
	else
	{
		b->right = findEnd(b->right);
		int check = checkBalance(b);
		//cout << "Check\t" << check << endl;

		if (check != 0)
		{
			//cout << "HELLO" << endl;
			b = determineFxn(b, check);
		}
		return b;
	}
}

//===============================================================================

int AVL::getH(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else return node->height;
}

int AVL::checkBalance(Node * parent)
{
	if (parent == NULL)
	{
		return 0;
	}

	if (getH(parent->left) > getH(parent->right)) //it is left heavy
	{
		parent->height = getH(parent->left) + 1;
		if (getH(parent->left) - getH(parent->right) > 1)
		{
			return -1;
		}
	}
	else //it is right heavy
	{
		parent->height = getH(parent->right) + 1;
		if (getH(parent->right) - getH(parent->left) > 1)
		{
			return 1;
		}
	}
	return 0;
}

Node* AVL::determineFxn(Node * parent, int check)
{

	if (check == 1) //right heavy rotate to the left
	{
		//cout << "CHECKPOINT 1" << endl;
		parent = balanceRight(parent);
	}
	else if (check == -1) //left heavy rotate to the right
	{
		//cout << "CHECKPOINT -1" << endl;
		parent = balanceLeft(parent);
	}
	else
	{
		return parent;
	}
	return parent;
}

Node * AVL::balanceLeft(Node* parent)
{
	//cout << "CHECKPOINT -2" << endl;
	Node* temp;
	//cout << "PARENT DATA\t" << parent->getData() << endl;
	if (getH(parent->left->right) > getH(parent->left->left)) //check logic
	{
		//cout << "CHECKPOINT -3" << endl;
		temp = parent->left;
		parent->left = temp->right;
		temp->right = parent->left->left;
		parent->left->left = temp;
	}
	//cout << "CHECKPOINT -4" << endl;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;

	checkBalance(temp->left);
	checkBalance(temp->right);
	checkBalance(temp);
	return temp;
}

Node * AVL::balanceRight(Node* parent)
{
	Node* temp;
	if (getH(parent->right->left) > getH(parent->right->right))
	{
		temp = parent->right;
		parent->right = temp->left;
		temp->left = parent->right->right;
		parent->right->right = temp;
	}
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;

	checkBalance(temp->left);
	checkBalance(temp->right);
	checkBalance(temp);
	return temp;
}

Node * AVL::traverse(Node* a)
{

}
