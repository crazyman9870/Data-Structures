/*
 * Student.h
 *
 *  Created on: Sep 26, 2014
 *      Author: aconstan
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "StudentInterface.h"

#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Student : public StudentInterface {
private:
	unsigned long long int id;
	string name;
	string address;
	string phone;
	double gpa;
	double weight; //This is the current GPA calculated from number of courses already included
	int courses; //This is the number of courses used to calculate the GPA thus far


public:
	Student(unsigned long long int id_in, string name_in, string address_in, string phone_in);
	virtual ~Student();

	unsigned long long int getId();
	string getName();
	string getGPA();
	void addGPA(double classGrade);
	string toString();
};

#endif /* STUDENT_H_ */
