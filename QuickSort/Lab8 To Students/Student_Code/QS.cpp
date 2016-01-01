/*
 * QS.cpp
 *
 *  Created on: Jun 13, 2014
 *      Author: aconstan
 */

#include "QS.h"

using namespace std;

QS::QS()
{
	EHRAY = NULL;
	cap = 0;
	cur_size = 0;
}

QS::~QS()
{
	clear();
}

//=============================================================================

/*
 * sortAll()
 *
 * Sorts elements of the array.  After this method is called, every
 * element in the array is less than or equal to the following element.
 *
 * Does nothing if the array is empty.
 */
void QS::sortAll()
{
	if (EHRAY == NULL)
	{
		return;
	}
	else
	{
		int l = 0;
		int r = cap - 1;

		sortrec(l, r);
	}
}

/*
 * medianOfThree()
 *
 * Performs median-of-three pivot selection from among the values in
 * the array between the two given indices. Median-of-three pivot
 * selection will sort the first, middle, and last elements in a given
 * array with respect to each other. After this method is called,
 * data[first] <= data[middle] <= data[last], where middle =
 * (first + last)/2.
 *
 * Returns -1 if the array is empty, if either of the given integers
 * is out of bounds, or if the first integer is not less than the second
 * integer.
 *
 * @param left
 * 		the left boundary for the subarray from which to find a pivot
 * @param right
 * 		the right boundary for the subarray from which to find a pivot
 * @return
 *		the index of the pivot; -1 if provided with invalid input
 */
int QS::medianOfThree(int left, int right)
{

	//cout << "CAP = " << cap << endl;
	//cout << "RIGHT\t" << right << endl;
	//cout << "LEFT\t" << left << endl;
	//cout << "RIGHT VALUE\t" << EHRAY[right] << endl;
	//cout << "LEFT VALUE\t" << EHRAY[left] << endl;

	if (EHRAY == NULL) //gaurd against empty array
	{
		return -1;
	}
	if (left < 0) // guard against left out of bounds
	{
		return -1;
	}
	if (right >= cap) //guard against right out of bounds
	{
		return -1;
	}
	if (left >= right) //guard against reversed input
	{
		return -1;
	}

	int index = left + ((right - left) / 2);
	int a;
	int b;

	/*if (right - left == 1)
	{
		if (EHRAY[right] < EHRAY[left])
		{
			swap(left, right);
			return index;
		}
	}*/

	if (EHRAY[left] > EHRAY[index]) //check left and index
	{
		a = EHRAY[index]; //assigns a the value in the index position
		EHRAY[index] = EHRAY[left];
		EHRAY[left] = a;
	}
	if (EHRAY[right] < EHRAY[index]) //check right and index
	{
		b = EHRAY[index]; //assigns b the value in the index position
		EHRAY[index] = EHRAY[right];
		EHRAY[right] = b;
	}
	if (EHRAY[left] > EHRAY[index]) //check left and index
	{
		a = EHRAY[index]; //assigns a the value in the index position
		EHRAY[index] = EHRAY[left];
		EHRAY[left] = a;
	}


	//cout << "MIDDLE\t" << index << endl;
	//cout << "MIDDLE VALUE\t" << EHRAY[index] << endl;

	//index = partition(left, right, index);

	return index;
}

/*
 * Partitions a subarray around a pivot value selected according to
 * median-of-three pivot selection.
 *
 * The values which are smaller than the pivot should be placed to the left
 * of the pivot; the values which are larger than the pivot should be placed
 * to the right of the pivot.
 *
 * Does nothing and returns -1 if the array is null, if either of the
 * given integers is out of bounds, or if the first integer is not less than
 * the second integer, or if the pivot is not between the two boundaries.
 *
 * @param left
 * 		the left boundary for the subarray to partition
 * @param right
 * 		the right boundary for the subarray to partition
 * @param pivotIndex
 * 		the index of the pivot in the subarray
 * @return
 *		the pivot's ending index after the partition completes; -1 if
 * 		provided with bad input
 */
int QS::partition(int left, int right, int pivotIndex)
{

	//cout << "\n\t\t\tPARTITION CALLED\n" << endl;


	if (EHRAY == NULL) //gaurd against empty array
	{
		return -1;
	}
	if (left < 0) // guard against left out of bounds
	{
		return -1;
	}
	if (right >= cap) //guard against right out of bounds
	{
		return -1;
	}
	if (left >= right) //guard against reversed input
	{
		return -1;
	}
	if (pivotIndex > right || pivotIndex < left) //guard against "index not in middle"
	{
		return -1;
	}

	int pvalue = EHRAY[pivotIndex];
	//printArray();

	swap(left, pivotIndex);

	int apos = left + 1;
	int bpos = right;


	//printArray();
	//cout << "PIVOT\t" << pvalue << endl;
	//cout << "PIVOTINDEX\t" << pivotIndex << endl;

	do
	{
		while (EHRAY[apos] < pvalue && apos != right)
		{
			apos++;
		}
		while (EHRAY[bpos] > pvalue && bpos != left)
		{
			bpos--;
		}
		//cout << "A\t" << EHRAY[apos] << endl;
		//cout << "APOS\t" << apos << endl;
		//cout << "B\t" << EHRAY[bpos] << endl;
		//cout << "BPOS\t" << bpos << endl;

		if (apos < bpos)
		{
			swap(apos, bpos);
		}

		//cout << "A\t" << EHRAY[apos] << endl;
		//cout << "APOS\t" << apos << endl;
		//cout << "B\t" << EHRAY[bpos] << endl;
		//cout << "BPOS\t" << bpos << endl;
		//cout << "\n\t\tWHILE LOOP SWAP\n" << endl;
	}while (apos < bpos);

	swap(bpos, left);

	/*pivotIndex = search_array(pvalue);*/
	//cout << "APOS\t" << apos << endl;
	//cout << "BPOS\t" << bpos << endl;
	//cout << "FINAL POS\t" << pivotIndex << endl;
	return bpos;
}

/*
 * Gets the array of values and puts them into a string. For example: if my array
 * looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
 * with no trailing comma.
 *
 * Does nothing and returns an empty string, if the array is null or empty.
 *
 * @return
 *		the string representation of the current array
 */
string QS::getArray()
{
	string final = "";
	string temp = "";
	for (int i = 0; i < cur_size; i++)
	{
		temp = int_to_string(EHRAY[i]);
		if (i == 0)
		{
			final = temp;
		}
		else
		{
			final += "," + temp;
		}
	}

	return final;
}

/*
 * Gets the current size of the current array.
 *
 * @return
 * 		the current size
 */
int QS::getSize()
{
	return cap;
}

/*
 * Adds the given value to the array.
 */
void QS::addToArray(int value)
{
	for (int i = 0; i < cap; i++)
	{
		if (EHRAY[cur_size] == -5)
		{
			EHRAY[cur_size] = value;
			cur_size++;

			break;
		}
	}
	//printArray();
}

/*
 * Creates an array of with the given size.
 *
 * Returns false if the given value is non-positive, true otherwise.
 *
 * @param
 *		size of array
 * @return
 *		true if the array was created, false otherwise
 */
bool QS::createArray(int size)
{
	//cout << "This is the array's size = " << size << endl;
	if (size < 0)
	{
		return false;
	}
	else
	{
		cap = size;
		//cout << "CAP = " << cap << endl;
		EHRAY = new int [size]; // ???

		//initialize the items in the array
		for (int i = 0; i < size; i++)
		{
			EHRAY[i] = -5;
		}

		//printArray();
		return true;
	}
}

/*
 * Clears the array.
 */
void QS::clear()
{
	delete[] EHRAY; //???
	cap = 0;
	cur_size = 0;
}

//===========================================================================

int QS::search_array(int value)
{
	int max = cap;
	int counter = 0;
	int find;
	while (counter < max)
	{
		find = EHRAY[counter];
		if (find == value)
		{
			return counter;
		}
		counter++;
	}
	return -1;
}

void QS::printArray()
{
	for (int i = 0; i < cap; i++)
	{
		cout << "pos " << i << " = " << EHRAY[i] << endl;
	}
}

string QS::int_to_string(int n)
{
	ostringstream strm;
	strm << n;
	return strm.str();
}

void QS::swap(int a, int b)
{
	int temp = EHRAY[a];
	EHRAY[a] = EHRAY[b];
	EHRAY[b] = temp;
}

void QS::sortrec(int left, int right)
{
	//cout << "LEFT\t" << left << endl;
	//cout << "RIGHT\t" << right << endl;

	if (right - left > 1)
	{

		int index = medianOfThree(left, right);
		/*if (index == -1)
		{
			return;
		}*/
		int pivot = partition(left, right, index);
		/*if (index == -1)
		{
			return;
		}*/


		sortrec(left, pivot - 1);

		sortrec(pivot + 1, right);


	}


	return;
}
