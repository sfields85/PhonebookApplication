#include "individual.h"

string Individual::getLast(){
      return lastName;                       
}
string Individual::getFirst(){
      return firstName;                       
}
string Individual::getPhone(){
      return phone;                       
}

void Individual::setLast(string last){
      lastName=last;                       
}

void Individual::setFirst(string first){
      firstName=first;                       
}

void Individual::setPhone(string ph){
      phone=ph;                       
}

/* Read Staff data from stream */
istream& operator >>(istream &is, Individual &obj) { 
         cout << setw(FIELD1) << "Enter First Name" <<  ": ";
         is >> obj.firstName;
         cout << setw(FIELD1) << "Enter Last Name" <<  ": ";
         is >> obj.lastName;
         cout << setw(FIELD1) << "Enter Phone" << ": ";
         is >> obj.phone;
         return is;
};
/* Write Staff data to stream */
ostream& operator <<(ostream &os, const Individual &obj){
         cout << " First Name" << ": " << obj.firstName;
         cout << " Last Name" <<  ": " << obj.lastName;
         cout << " Phone" << ": " << obj.phone;
         return os;
};
