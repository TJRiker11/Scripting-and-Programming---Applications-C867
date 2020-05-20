#include "stdafx.h"
#include "student.h"

int Student::getAge()
{
	return Age;
}

int * Student::getDaysInCourse()
{
	return DaysInCourse;
}

string Student::getEmail()
{
	return Email;
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
}

string Student::getStudentId()
{
	return StudentId;
}

Degree Student::getDegreeType()
{
	return Degree();
}

void Student::setAge(int age)
{
	Age = age;
}


void Student::setDaysInCourse(int *daysInCourse)
{
	for (int i = 0; i < 3; i++) {
		DaysInCourse[i] = daysInCourse[i];
	}
}

void Student::setEmail(string email)
{
	Email = email;
}

void Student::setFirstName(string firstName)
{
	FirstName = firstName;
}

void Student::setLastName(string lastName)
{
	LastName = lastName;
}

void Student::setStudentId(string studentId)
{
	StudentId = studentId;
}

void Student::setDegreeType(Degree degreeType)
{
	DegreeType = degreeType;
}

Student::Student(int age, int daysInCourse[3], string studentId, string email, string firstName, string lastName, Degree degreeType)
{
	setAge(age);
	setStudentId(studentId);
	setEmail(email);
	setFirstName(firstName);
	setLastName(lastName);
	setDegreeType(degreeType);
	setDaysInCourse(daysInCourse);
	setDegreeType(degreeType);
}

void Student::print()
{
	int *daysInCourse = getDaysInCourse();

	cout << getStudentId() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "daysInCourse: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}\t";

	cout << "Degree Program: ";
	switch (getDegreeProgram()) {
	case 0: cout << "Security";
		break;
	case 1: cout << "Networking";
		break;
	case 2: cout << "Software";
		break;
	case 4: cout << "Other";
		break;
	}
	cout << "\n";
}

Degree Student::getDegreeProgram()
{
	return OTHER;
}


Student::~Student()
{
}
