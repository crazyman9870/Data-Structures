/*
 * GPA.h
 *
 *  Created on: Sep 26, 2014
 *      Author: aconstan
 */

#ifndef GPA_H_
#define GPA_H_

#include "GPAInterface.h"
#include "Student.h"

#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class GPA : public GPAInterface {
private:
	map<unsigned long long int, StudentInterface*> smap;
	set<StudentInterface*, Comparator> sset;
	map<string, double> grades;

	//Iterators
	typedef set<StudentInterface*, Comparator>::iterator setIter;
	typedef map<unsigned long long int, StudentInterface*>::iterator mapIter;


public:
	GPA();
	virtual ~GPA();

	map<unsigned long long int,StudentInterface*> getMap();
	set<StudentInterface*,Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();
	//==========================================================
	bool isValidStudentFile(string fName);
	bool isValidGradeFile(string fName);
	bool importStudentFileMap(string mapFileName);
	bool importStudentFileSet(string setFileName);
	bool validQuery(string fileName);

	bool updateGrade(unsigned long long int id, string grade);
	double getGrade(string letter);
	//====================================================================
	int string_to_int(string s);
	string longToString(unsigned long long int id);
	void clearMap();
	void clearSet();
	void printSet();
	void printMap();

	bool findMap(unsigned long long int id);
	bool findSet(unsigned long long int id);
	StudentInterface* findInMap(unsigned long long int id);
	StudentInterface* findInSet(unsigned long long int id);
};

#endif /* GPA_H_ */
