/* header file for Individual class */
#ifndef _INDIVIDUAL_H
// this ifndef/define to prevent multiple inclusions
#define _INDIVIDUAL_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const static int FIELD1=18; // used to format I/O
  
class Individual {
      private:
          /* Individual's data */
          string lastName;
          string firstName;
          string phone;
          
          
      public:
           /* Accessor methods to get access to private members */
           string getLast();
           string getFirst();
           string getPhone();

           void setLast(string last);
           void setFirst(string first);
           void setPhone(string ph);
           
        
           friend istream& operator >>(istream &is, Individual &obj);
           friend ostream& operator <<(ostream &os, const Individual &obj);

};
#endif
