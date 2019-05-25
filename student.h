#ifndef _STUDENT_H
#define _STUDENT_H

#include "individual.h"

/* Student - derived from Individual */
class Student : public Individual {
      private:  
          double gpa; /* gpa total */
          int hours;  /* hours currently enrolled */
       
      public: /* Accessor methods, inline implementation */
          double getGPA();   
          int getHours ();
           
          void setGPA(double newGPA);
          void setHours(int newHours);
          
       
           /* We allow direct access to private members for friend functions */
           friend istream& operator >>(istream &is, Student &obj);
           friend ostream& operator <<(ostream &os, const Student &obj);
          
};
#endif
