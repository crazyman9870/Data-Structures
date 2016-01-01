/*
 * Node.h
 *
 *  Created on: Jun 6, 2014
 *      Author: aconstan
 */

#ifndef NODE_H_
#define NODE_H_

#include "NodeInterface.h"

using namespace std;

class Node : public NodeInterface
{
private:



public:
	Node(int data_item, Node* right_ptr, Node* left_ptr);
	virtual ~Node();

	int data;
	Node* right;
	Node* left;

	int getData();

	NodeInterface * getLeftChild();

	NodeInterface * getRightChild();

	//==================================================================



};

#endif /* NODE_H_ */
