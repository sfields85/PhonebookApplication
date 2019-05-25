#include "student.h"

/* Student - derived from Individual */
/* class implementation */
double Student::getGPA() { return gpa; };   
int Student::getHours () { return hours; };
void Student::setGPA(double newGPA) { gpa=newGPA;};
void Student::setHours(int newHours) { hours=newHours;};

/* Read Student's data from stream */
istream& operator >>(istream &is, Student &obj) {
         cout << "Adding new student..." << endl;
         is >> (Individual&) obj; // Enter First, Last name and Phones
         cout << setw(FIELD1) << "Enter GPA" << ": ";
         is >> obj.gpa;
         cout << setw(FIELD1) << "Enter hours" << ": ";
         is >> obj.hours;
         cout << "New student has been added." << endl;
         return is;
};
/* Write Student's data to stream */
ostream& operator <<(ostream &os, const Student &obj){
         os << (Individual&) obj;
         cout << " GPA" << ": " << obj.gpa;
         cout << " Hours" << ": " << obj.hours;
         return os;
};
