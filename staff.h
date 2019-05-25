#ifndef _STAFF_H
#define _STAFF_H

#include "individual.h"

/* Staff - derived from Individual */
class Staff : public Individual {
      private:
      string job; /* Job description */
      int year; /* employment year */
          string getJob();   
          int getYear ();
           
        void setJob(string newJob);
        void setYear(int newYear);
 
        /* Allow direct access to private members for << and >> operators */
        friend istream& operator >>(istream &is, Staff &obj);
        friend ostream& operator <<(ostream &os, const Staff &obj);

};
#endif
