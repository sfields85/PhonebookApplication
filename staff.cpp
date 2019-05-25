#include "staff.h"

/* Staff - derived from Individual */
string Staff::getJob() { return job; };   
int Staff::getYear () { return year; };
           
void Staff::setJob(string newJob) { job=newJob;};
void Staff::setYear(int newYear) { year=newYear;};

/* Read Staff data from stream */
istream& operator >>(istream &is, Staff &obj) {
         cout << "Adding new staff member..." << endl;
         is >> (Individual&) obj; // Enter First, Last name and Phones
         cout << setw(FIELD1) << "Enter Job title" << ": ";
         is >> obj.job;
         cout << setw(FIELD1) << "Enter Year employed" << ": ";
         is >> obj.year;
         cout << setw(FIELD1) << "New staff entry has been added." << endl;
         return is;
};
/* Write Staff data to stream */
ostream& operator <<(ostream &os, const Staff &obj){
         os << (Individual&) obj;
         cout << setw(FIELD1) << " Job" << ": " << obj.job;
         cout << setw(FIELD1) << " Year" <<": " << obj.year;
         return os;
};
