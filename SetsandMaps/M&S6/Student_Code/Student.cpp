/*
 * Student.cpp
 *
 *  Created on: Sep 26, 2014
 *      Author: aconstan
 */

#include "Student.h"

#include<iostream>

Student::Student(unsigned long long int id_in, string name_in, string address_in, string phone_in)
{
	id = id_in;
	name = name_in;
	address = address_in;
	phone = phone_in;

	gpa = 0.00;
	weight = 0.00;
	courses = 0;
/*	cout << "Student created with these values\n";
	cout << id << endl;
	cout << name << endl;
	cout << address << endl;
	cout << phone << endl;
	cout << gpa << weight << courses << endl;*/
}

Student::~Student() {
}

/*
 * getId()
 *
 * Returns the ID of the Student.
 */
unsigned long long int Student::getId()
{
	return id;
}

/*
 * getName()
 *
 * Returns the name of the Student
 */
string Student::getName()
{
	return name;
}

/*
 * getGPA()
 *
 * Returns the string representation of the Student's GPA.
 */
string Student::getGPA()
{
	stringstream ss;
	if(courses > 0)
	{
		gpa = weight/courses;
	}
	ss << fixed << setprecision(2) << gpa;
	//cout << "THIS IS THE GPA =\t" << ss.str() << endl;

	return ss.str();
}

/*
 * addGPA()
 *
 * Incorporates the given course grade into the Student's overall GPA.
 */
void Student::addGPA(double classGrade)
{
	weight += classGrade;
	courses++;
}

/*
 * toString()
 *
 * The student object will be put into string representation. Student info will be
 * ordered ID, name, address, phone number, and GPA. Each piece of information will
 * be on its own line. GPA will not have a newline following it and the precision
 * of the GPA will be set to two decimal places. For example,
 *
 * 123456789
 * Ben Thompson
 * 17 Russell St, Provo, UT 84606
 * 555-555-5555
 * 3.12
 *
 * Returns a string representation of the student object.
 */
string Student::toString()
{
	stringstream ss;

	ss << id << "\n";
	ss << name << "\n";
	ss << address << "\n";
	ss << phone << "\n";
	ss << getGPA();// << "\n";

	return ss.str();
}


