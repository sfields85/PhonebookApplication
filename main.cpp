#include <cstdlib>

#include "individual.h"
#include "student.h"
#include "staff.h"

using namespace std;

enum {MENU_CREATE_NEW=1, MENU_FIND_ENTRY=2, MENU_DISPLAY_ALL=3, MENU_EXIT=4, 
      MENU_STUDENT=1, MENU_STAFF=2}; // that's amother level, so we can use 1,2

/* Shows main menu and return an integer (menu choice) */ 
int showMainMenu(){
     int choice;
     cout << endl << " Please your choice (menu number): " << endl;
     cout <<         " ================================= " << endl;
     cout <<         " 1. Create a new phonebook entry.  " << endl;
     cout <<         " 2. Find phonebook entry.  " << endl;
     cout <<         " 3. Display all entries.  " << endl;
     cout <<         " 4. Exit.  " << endl;
     
     cin >> choice;

     return choice;
}

/* Simple menu to select a kind of person we are adding */
int showMenuStudentOrStaff(){
    int choice;
    cout << endl;
    cout << " Please select a kind of entry we are adding: " << endl;
    cout << " 1. Student" << endl;
    cout << " 2. Staff" << endl;
    cin >> choice;
    return choice;
}

/* Show menu to enter the last name */
/* Return entered string */
string showMenuFind(){
    string findMe;
    cout << "Last name to find: ";
    cin >> findMe;
    return findMe;
}

int main(int argc, char *argv[])
{
    int  numStud=0, numStaff=0;
    int choice;
    Student studPhoneBook[10];
    Staff stafPhoneBook[10];
    string findMe;
    bool entryFound;
    
    /* Show main menu and get choice (we expect 1..4) */
    while(choice != MENU_EXIT){
       choice=showMainMenu(); 

       switch (choice){
         case MENU_CREATE_NEW: // Create new entry
           // Now ask if we want to add a student or staff entry
           switch(choice=showMenuStudentOrStaff()){
             case MENU_STUDENT:
                  // here is the power of >> overloading
                  cin >> studPhoneBook[numStud++];
                  break;
             case MENU_STAFF:
                  cin >> stafPhoneBook[numStaff++];
                  break;
             default: // ignore
               break;
           }
           break;
         
         
         case MENU_FIND_ENTRY: // Find entry
            findMe=showMenuFind(); // last name to find
            entryFound = false; // by default not found
            
           // First search in students
           for(int i=0; i<numStud; i++){
             if (studPhoneBook[i].getLast().compare(findMe)==0){
               entryFound=true;
               cout << studPhoneBook[i] << endl; // display if found
             }
           }
           // Next try to find staff
           for (int i=0; i<numStaff; i++){
             if (stafPhoneBook[i].getLast().compare(findMe)==0){
               entryFound=true;
               cout << stafPhoneBook[i] << endl; // display if found
               }
           }
         
           // Now check if at least 1 entry was matching our criteria
           if (!entryFound) cout << endl << findMe << " NOT FOUND" << endl; 
           break;
           
           
         case MENU_DISPLAY_ALL: // Display all
           // First display students
           for(int i=0; i<numStud; i++){
             cout << studPhoneBook[i] << endl; // display Students
           }
           // Next display staff
           for (int i=0; i<numStaff; i++){
               cout << stafPhoneBook[i] << endl; // display Staff members
           }
           break;
         
         case MENU_EXIT: // Exit on the next loop
           break;
         
         default: // Ignore       
           break;  
       };
    };
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
