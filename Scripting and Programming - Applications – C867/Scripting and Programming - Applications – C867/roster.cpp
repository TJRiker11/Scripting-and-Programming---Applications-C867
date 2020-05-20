#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

int main() {

	Roster classRoster;

	cout << "Course Title: Scripting and Programming - Applications - C867 \n";
	cout << "Language: C++ \n";
	cout << "Student ID: #000807444 \n";
	cout << "Name: Thomas Riker \n";

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Thomas,Riker,triker8@wgu.edu,19,10,12,15,SOFTWARE"
	};

	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string tempHolder[9];

		int x = 0;
		while (getline(ss, token, ',')) {
			tempHolder[x] = token;
			x += 1;
		}

		Degree theDegree;
		if (tempHolder[8] == "NETWORK") {
			theDegree = NETWORKING;
		}
		else if (tempHolder[8] == "SECURITY") {
			theDegree = SECURITY;
		}
		else if (tempHolder[8] == "SOFTWARE") {
			theDegree = SOFTWARE;
		}
		else {
			theDegree = OTHER;
		}

		classRoster.add(tempHolder[0], tempHolder[1], tempHolder[2], tempHolder[3], std::stoi(tempHolder[4]), std::stoi(tempHolder[5]), std::stoi(tempHolder[6]), std::stoi(tempHolder[7]), theDegree);
	}

	classRoster.printAll();
	cout << "\n";
	classRoster.printInvalidEmails();
	cout << "\n";
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}
	cout << "\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n";
	classRoster.remove("A3");
	classRoster.remove("A3");

	return 0;

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] == nullptr) {
			if (degreeProgram == NETWORKING) {
				classRosterArray[i] = new NetworkStudent(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram);
			}
			else if (degreeProgram == SECURITY) {
				classRosterArray[i] = new SecurityStudent(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram);
			}
			else if (degreeProgram == SOFTWARE) {
				classRosterArray[i] = new SoftwareStudent(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram);
			}
			else {
				classRosterArray[i] = new Student(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram);
			}

			break;
		}
	}
}

void Roster::printAll()
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printDaysInCourse(string studentID)
{
	float avg = 0;
	int max = 3;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
			int *daysInCourse = classRosterArray[i]->getDaysInCourse();
			for (int x = 0; x < max; x++) {
				avg += daysInCourse[x];
			}

			cout << "Student " << classRosterArray[i]->getStudentId() << "'s average number of days to complete 3 classes is: " << (avg / max) << "\n";
			break;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		string email = classRosterArray[i]->getEmail();
		bool isValid = false;
							 				 

		size_t found = email.find("@");
		if (found != string::npos) {
			found = email.find(".");
			if (found != string::npos) {
				found = email.find(" ");
				if (found == string::npos) {
					isValid = true;
				}
			}
		}

		if (!isValid) {
			cout << email << " INVALID \n";
		}
	}
}

void Roster::remove(string studentID)
{
	bool studentRemoved = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
			classRosterArray[i] = nullptr;
			studentRemoved = true;
			break;
		}
	}

	if (studentRemoved == false) {
		cout << "Student ID:'" << studentID << "' Not Found  \n";
	}
}


Roster::~Roster()
{
	cout << "Calling destrustor to delete class roster -- Deleting Roster \n";
	delete[] *classRosterArray;
}