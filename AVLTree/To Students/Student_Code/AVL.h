/*
 * AVL.h
 *
 *  Created on: Jun 17, 2014
 *      Author: aconstan
 */

#ifndef AVL_H_
#define AVL_H_

#include "AVLInterface.h"
#include "Node.h"

#include <iostream>

using namespace std;

class AVL : public AVLInterface
{
private:

	Node* root;
	bool found;
	int end;



public:
	AVL();
	virtual ~AVL();

	NodeInterface * getRootNode();

	bool add(int data);

	bool remove(int data);

	//======================================================================

	void clear();

	//======================================================================

	void duplicate(Node* a, int data);

	Node * addNode(Node* a, int data);

	Node * removeNode(Node* a, int data);

	Node * findEnd(Node* b);

	//======================================================================

	int getH(Node* node);

	int checkBalance(Node * parent);

	Node* determineFxn(Node * parent, int check);

	Node * balanceLeft(Node* parent);

	Node * balanceRight(Node* parent);

	Node * traverse(Node* start);

};

#endif /* AVL_H_ */
