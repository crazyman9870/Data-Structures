/*
 * GPA.cpp
 *
 *  Created on: Sep 26, 2014
 *      Author: aconstan
 */

#include "GPA.h"

GPA::GPA() {
	grades.insert(pair<string, double>("A",4.0));
	grades.insert(pair<string, double>("A-",3.7));
	grades.insert(pair<string, double>("B+",3.4));
	grades.insert(pair<string, double>("B",3.0));
	grades.insert(pair<string, double>("B-",2.7));
	grades.insert(pair<string, double>("C+",2.4));
	grades.insert(pair<string, double>("C",2.0));
	grades.insert(pair<string, double>("C-",1.7));
	grades.insert(pair<string, double>("D+",1.4));
	grades.insert(pair<string, double>("D",1.0));
	grades.insert(pair<string, double>("D-",0.7));
	grades.insert(pair<string, double>("E",0.0));
}

GPA::~GPA() {
	clear();
}

/*
 * getMap()
 *
 * Returns the map storing the student information.
 * The key of the map should be the student ID.
 */
map<unsigned long long int,StudentInterface*> GPA::getMap()
{
	return smap;
}

/*
 * getSet()
 *
 * Returns the set storing the student information.
 */
set<StudentInterface*,Comparator> GPA::getSet()
{
	return sset;
}

/*
 * importStudents()
 *
 * Read in and parse through the given files. Each part of an entry in a
 * file is given on a separate line in the file. Student ID is first, name is
 * second, address is third, and phone is last. There are no blank lines between
 * students. The following is an example file:
 *
 *	 5291738600
 * 	 Dick B. Smith
 * 	 879 Maple Road, Centralia, Colorado 24222
 * 	 312-000-1000
 * 	 9251738707
 *	 Harry C. Anderson
 *	 635 Main Drive, Midville, California 48444
 * 	 660-050-2200
 *
 * If a valid file is given, the new Students should be added to the existing
 * map and set, respectively.
 *
 * If an invalid file name is given or if there is a missing entry for a student,
 * return false. If the function returns false, then no changes should have been made
 * to the existing map or set.
 *
 * The key of the map should be the student ID.
 *
 *	Returns false if an invalid filename is given or if there is a missing entry for a
 *	student, otherwise true.
 */
bool GPA::importStudents(string mapFileName, string setFileName)
{
	if(!isValidStudentFile(mapFileName))
		return false;
	if(!isValidStudentFile(setFileName))
		return false;

	importStudentFileMap(mapFileName);
	importStudentFileSet(setFileName);

	return true;
}

/*
 * importGrades()
 *
 * Read in and parse through the given file. Each part of an entry in the file
 * is given on a separate line in the file. Student ID is first, course is
 * second, and grade is last. There are no blank lines between entries. The
 * following is an example file:
 *
 * 	5291738860
 * 	CHEM134
 * 	A
 * 	9251734870
 * 	BOT180
 * 	B
 * 	9251733870
 * 	PE273
 * 	D+
 * 	5291738760
 * 	HIS431
 *  A-
 *
 * Compute the GPA by finding the average of all the grades with a matching student ID
 * in the Grade file. The GPA is calculated by taking a Student's total sum GPA and
 * dividing by the number of classes taken. If the given student ID has no matching
 * grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
 * names so long as the total number of courses taken is counted.
 *
 * You may assume that the given student ID exists in the map or set.
 *
 * Use the following point values for each grade.
 *
 *		      A = 4.0  A- = 3.7
 *	B+ = 3.4  B = 3.0  B- = 2.7
 *	C+ = 2.4  C = 2.0  C- = 1.7
 *	D+ = 1.4  D = 1.0  D- = 0.7
 *		      E = 0.0
 *
 * Returns false if an invalid filename is given, otherwise true.
 */
bool GPA::importGrades(string fileName)
{
	if(!isValidGradeFile(fileName))
	{
		return false;
	}

	fstream gradeFile;
	gradeFile.open(fileName.c_str());

	unsigned long long int id = 0;
	while (gradeFile>>id) {

		gradeFile.ignore();

		string className = "";
		getline(gradeFile, className);
		if(className == "") {
			return false;
		}
		//This name is useless and is only needed to read the file correctly

		string grade = "";
		getline(gradeFile, grade);
		if(grade == "") {
			return false;
		}

		updateGrade(id, grade);

	}

	return true;
}

/*
 * querySet()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your set to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. If an invalid file name is given,
 * then return an empty string. The precision of the GPA will be set to two decimal places.
 */
string GPA::querySet(string fileName)
{
	if(!validQuery(fileName))
		return "";

	//cout << "PRINTING SET\n";
	//printSet();

	string output = "";
	fstream file;

	file.open(fileName.c_str());

	unsigned long long int id = 0;
	while(file >> id)
	{
		//cout << "ID NUMBER" << id << endl;

		StudentInterface* temp = findInSet(id);


		if(temp != NULL)
		{
			output += longToString(id) + " " + temp->getGPA() + " " + temp->getName() + "\n";
		}

	}

	//cout << "HERE\n\n\n" << output << "\n";
	return output;
}

/*
 * queryMap()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your map to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. if an ivalid file name is given,
 * then return an empty string. The precision of the GPA will be set to two decimal places.
 */
string GPA::queryMap(string fileName)
{
	if(!validQuery(fileName))
		return "";

	string output = "";
	fstream file;

	file.open(fileName.c_str());

	unsigned long long int id = 0;
	while(file >> id)
	{
		StudentInterface* temp = findInMap(id);

		if(temp != NULL)
		{
			output += longToString(id) + " " + temp->getGPA() + " " + temp->getName() + "\n";
		}
	}

	//cout << output << "\n";
	return output;
}

/*
 * Clears the students from the map and set.
 */
void GPA::clear()
{
	clearMap();
	smap.clear();
	clearSet();
	sset.clear();
}

//==========================================================
bool GPA::isValidStudentFile(string fName)
{
	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return false;

	unsigned long long int idNum;
	while (in >> idNum)
	{
		in.ignore();

		string name = "";
		getline(in, name);
		if (name == "")
			return false;

		string address = "";
		getline(in, address);
		if (address == "")
			return false;

		string phone = "";
		getline(in, phone);
		if (phone == "")
			return false;

	}

	if (!in.eof())
		return false;

	in.close();

	return true;
}

bool GPA::isValidGradeFile(string fName)
{
	ifstream in;
	in.open(fName.c_str());

	if (in.fail())
		return false;

	unsigned long long int idNum;

	while (in >> idNum)
	{
		in.ignore();

		string className = "";
		getline(in, className);
		if (className == "")
			return false;


		string grade = "";
		getline(in, grade);
		if (grade == "")
			return false;
	}

	if (!in.eof())
		return false;

	in.close();

	return true;
}

bool GPA::importStudentFileMap(string mapFileName)
{
	fstream mapFile;
	mapFile.open(mapFileName.c_str());

	if(mapFile.fail())
	{
		return false;
	}

	unsigned long long int id = 0;
	while (mapFile>>id)
	{
		mapFile.ignore();

		string name = "";
		getline(mapFile, name);

		string address = "";
		getline(mapFile, address);

		string phone = "";
		getline(mapFile,phone);

		StudentInterface* s = new Student(id, name, address, phone);
		smap.insert(pair<unsigned long long int,StudentInterface*>(id, s));
	}

	mapFile.close();
	return true;
}

bool GPA::importStudentFileSet(string setFileName)
{
	fstream setFile;
	setFile.open(setFileName.c_str());

	if(setFile.fail())
	{

		return false;
	}

	unsigned long long int id = 0;
	while (setFile>>id)
	{
		setFile.ignore();

		string name = "";
		getline(setFile, name);

		string address = "";
		getline(setFile, address);

		string phone = "";
		getline(setFile,phone);

		StudentInterface* s = new Student(id, name, address, phone);

		sset.insert(s);
	}

	setFile.close();
	return true;
}

bool GPA::validQuery(string fileName)
{
	fstream test;
	test.open(fileName.c_str());

	if(test.fail())
		return false;

	unsigned long long int id;
	while(test >> id){}

	if(!test.eof())
		return false;

	return true;
}


bool GPA::updateGrade(unsigned long long int id, string grade)
{
	if(!findMap(id) && !findSet(id))
		return false;

	if(findMap(id) && findSet(id))
		return false;

	double score = getGrade(grade);

	if(findMap(id))
	{
		for(mapIter it = smap.begin(); it != smap.end(); ++it)
		{
			if(it->first == id)
			{
				it->second->addGPA(score);
			}
		}
	}

	if(findSet(id))
	{
		for(setIter it = sset.begin(); it != sset.end(); ++it)
		{
			if((*it)->getId() == id)
			{
				(*it)->addGPA(score);
			}
		}
	}

	return true;
}

double GPA::getGrade(string letter)
{
	for(map<string, double>::iterator it = grades.begin(); it != grades.end(); ++it)
	{
		if(it->first == letter)
		{
			return it->second;
		}
	}
	return -1.00;
}

//========================================================================
int GPA::string_to_int(string str)
{
	int n;
	stringstream ss;
	ss << str;
	ss >> n;

	return n;
}

string GPA::longToString(unsigned long long int id)
{
	stringstream ss;
	ss << id;
	return ss.str();
}

void GPA::clearMap()
{
	for (std::map<unsigned long long int, StudentInterface*>::iterator it = smap.begin();
			it != smap.end(); ++it)
	{
		StudentInterface* destroy = it->second;
		delete destroy;
	}
}

void GPA::clearSet()
{
	for (std::set<StudentInterface*, Comparator>::iterator it = sset.begin();
				it != sset.end(); ++it)
	{
		StudentInterface* destroy = *it;
		delete destroy;
	}
}

void GPA::printSet()
{
	for (setIter it = sset.begin(); it != sset.end(); ++it)
	{
		cout << (it == sset.begin() ? "": "\n\n") << (*it)->toString() << endl;
		//cout << "ID: " << (*it)->getID() << "\tStudent: " << (*it)->getName() << endl;
	}

}

void GPA::printMap()
{

	for (mapIter it = smap.begin(); it != smap.end(); ++it)
	{
		cout << (it == smap.begin() ? "": "\n\n") << it->second->toString() << endl;
		//cout << "ID: " << it->second->getID() << "\tStudent: " << it->second->getName() << endl;
	}
}

bool GPA::findMap(unsigned long long int id)
{

	for(mapIter it = smap.begin(); it != smap.end(); ++it) {

		if(it->first == id)
		{
			return true;
		}
	}
	return false;
}

bool GPA::findSet(unsigned long long int id)
{

	for(setIter it = sset.begin(); it != sset.end(); ++it) {

		if((*it)->getId() == id)
		{
			return true;
		}
	}
	return false;
}

StudentInterface* GPA::findInMap(unsigned long long int id)
{
	for(mapIter it = smap.begin(); it != smap.end(); ++it) {

		if(it->first == id)
		{
			return it->second;
		}
	}
	return NULL;
}

StudentInterface* GPA::findInSet(unsigned long long int id)
{
	for(setIter it = sset.begin(); it != sset.end(); ++it) {

		if((*it)->getId() == id)
		{
			return (*it);
		}
	}
	return NULL;
}



