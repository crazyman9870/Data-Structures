/*
 * Node.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: aconstan
 */

#include "Node.h"

using namespace std;

Node::Node(int data_item, Node* right_ptr, Node* left_ptr)
{
	data = data_item;
	right = right_ptr;
	left = left_ptr;
	height = 1;
}

Node::~Node()
{

}

/*
 * Returns the data that is stored in this node
 *
 * @return the data that is stored in this node.
 */
int Node::getData()
{
	return data;
}

/*
 * Returns the left child of this node or null if it doesn't have one.
 *
 * @return the left child of this node or null if it doesn't have one.
 */
NodeInterface * Node::getLeftChild()
{
	return left;
}

/*
 * Returns the right child of this node or null if it doesn't have one.
 *
 * @return the right child of this node or null if it doesn't have one.
 */
NodeInterface * Node::getRightChild()
{
	return right;
}

/*
 * Returns the height of this node. The height is the number of edges
 * from this node to this nodes farthest child.
 */
int Node::getHeight()
{
	return height;
}

//=====================================================================================





