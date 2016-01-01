/*
 * BLT.h
 *
 *  Created on: Jun 6, 2014
 *      Author: aconstan
 */

#ifndef BLT_H_
#define BLT_H_

#include "BSTInterface.h"
#include "Node.h"
#include <iostream>


using namespace std;

class BST : public BSTInterface
{
private:


	Node* root;
	bool found;
	//bool success;
	int end;


public:
	BST();
	virtual ~BST();

	NodeInterface * getRootNode();

	bool add(int data);

	bool remove(int data);

	void clear();

	//=======================================================================

	void duplicate(Node* a, int data);

	Node * addNode(Node* a, int data);

	Node * removeNode(Node* a, int data);

	Node * findEnd(Node* b);



};


#endif /* BLT_H_ */
