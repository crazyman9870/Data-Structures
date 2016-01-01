/*
 * QS.h
 *
 *  Created on: Jun 13, 2014
 *      Author: aconstan
 */

#ifndef QS_H_
#define QS_H_

#include "QSInterface.h"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

class QS : public QSInterface
{

private:

	int* EHRAY;
	int cap;
	int cur_size;

public:
	QS();
	virtual ~QS();


	//================================================================================

	void sortAll();

	int medianOfThree(int left, int right);

	int partition(int left, int right, int pivotIndex);

	string getArray();

	int getSize();

	void addToArray(int value);

	bool createArray(int size);

	void clear();

	//==================================================================================

	int search_array(int value);

	void printArray();

	string int_to_string(int n);

	void swap(int a, int b);

	void sortrec(int left, int right);
};


#endif /* QS_H_ */
