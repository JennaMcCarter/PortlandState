//Jenna McCarter
//CS 162
// Assignment 3
// Create a program that helps you in planning for the next important events

#include <iostream>
#include <fstream>
#include <cctype>
#include<cstring>
using namespace std;

//CONSTANTS
   const int TYPE = 131;
   const int TERM =15;
   const int PREPARE =131;
   const int PROBLEMS =131;
   const int OTHER =131;
   const int EVENTS = 20; //holds how many events memory can hold
   const int ALL = 150;  // helps displayAll to to display all information
   const int MONTH = 11;  //
   const int YEAR = 15;

//STRUCTS
struct event {
   char type [TYPE]; //holds what type of event is being planned (ex. class)
   char term [TERM]; //holds what term it will take place (ex. fall, winter)
   char year [YEAR]; // holds what year event will take place
   char prepare [PREPARE]; //holds what they need to do to prepare
   char problems [PROBLEMS]; // what they need to do if there is a problem
   char other [OTHER]; //holds additional information
};

//PROTOTYPES
   bool again();
   void addEvent(event & activity);
   bool compareArrays (char playerArray, char fileArray);

//MAIN
int main () {
   //Step 1: Declare Variables
   int playerAnswer = 0; // holds user input from user menu
   int countEvents = 0; //counts how many events someone has entered
   event activity [EVENTS];
   int eventsToAdd = 0; //keeps track of which new events to add to file
   ofstream file_out;
   ifstream file_in;
   char displayAll [ALL]; // helps to display all information
   event displayTerm [EVENTS];
   char playerMonth [MONTH]; //player chooses which month to look at
   char playerYear[YEAR];  // player chooses which year to look at

   //Step 2: create  user option menu
   cout << "This is a program that will help you manage your events" << endl;
   do {
      cout << "Enter the number of the activity you wish to do next." << endl;
      cout << "   ----------------------------------------------------------"
           << endl;
      cout << "   | 1. Add an event.                                       | "
           << endl;
      cout << "   | 2. Display all activities.                             |"
           << endl;
      cout << "   | 3. Display all activities for a certain term and year. |"
           << endl;
      cout << "   | 4. Quit.                                               |"
           << endl;
      cout << "   ----------------------------------------------------------"
           << endl << endl;
      cout << "   What would you like to do: ";

      cin  >> playerAnswer;
      cin.ignore (100, '\n');
      cout << endl << endl;

      //OPTION 1 -- ADD A NEW EVENT TO THE EXTERNAL FILE
      if (1 == playerAnswer){
         do {
            addEvent(activity[countEvents]);
            ++countEvents;
         } while (countEvents < EVENTS &&  again()); //end do while loop

        //Add information to external file
        file_out.open("assignment3.txt", ios::app);
        while (eventsToAdd < countEvents){
           file_out << "Activity:";
           file_out << activity[eventsToAdd].type << endl;
           file_out << "Term:";
           file_out << activity[eventsToAdd].term << endl;
           file_out << "Year:";
           file_out << activity[eventsToAdd].year << endl;
           file_out << "How to Prepare:";
           file_out << activity[eventsToAdd].prepare << endl;
           file_out << "Any Problems:";
           file_out << activity[eventsToAdd].problems << endl;
           file_out << "Additional Information:";
           file_out << activity[eventsToAdd].other << endl;
           ++eventsToAdd;
        }
        file_out.close();
      }

      //OPTION 2 -- DISPLAYS ALL EVENTS IN THE EXTERNAL FILE
      else if  (2 == playerAnswer){
         file_in.open ("assignment3.txt");
         int  addSpace =0;
         while (!file_in.eof()){
            file_in.get(displayAll, ALL, '\n');
            file_in.ignore(100, '\n');
            cout << displayAll << endl;
            ++addSpace;
            if (addSpace == 6){
               addSpace =0;
               cout << endl;
            }
         }
         file_in.close();
      }

      //OPTION 3 -- DISPLAY EVENTS FROM A CERTAIN TERM AND YEAR
      else if  (3 == playerAnswer){
         //asks user which term and year
         cout << "Which year would you like to see?" << endl;
         cout << "   Year: ";
         cin  >> playerYear;
         cin.ignore(100, '\n');
         cout << "Which term  would you like to see?" << endl;
         cout << "   Term: ";
         cin >> playerMonth;
         cin.ignore(100, '\n');
         cout << endl << endl;

         //looks for all related information
         //displayTerm
        char tempType [TYPE], tempTerm[TERM], tempYear[YEAR],
        tempPrepare[PREPARE],tempProblems[PROBLEMS], tempOther[OTHER];

         file_in.open ("assignment3.txt");
         while (!file_in.eof()){
            file_in.get(tempType, TYPE, '\n');
            file_in.ignore(100, '\n');
            file_in.get(tempTerm, TERM, ':');
            file_in.ignore(100, ':');
            file_in.get(tempTerm, TERM, '\n');
	    file_in.ignore(100, '\n');
            file_in.get(tempYear, YEAR, ':');
            file_in.ignore(100, ':');
            file_in.get(tempYear, YEAR, '\n');
            file_in.ignore(100, '\n');
            file_in.get(tempPrepare, PREPARE, '\n');
            file_in.ignore(100, '\n');
            file_in.get(tempProblems, PROBLEMS, '\n');
            file_in.ignore(100, '\n');
            file_in.get(tempOther, OTHER, '\n');
            file_in.ignore(100, '\n');


            if (strcmp(tempTerm,playerMonth) == 0 &&
                strcmp(tempYear,playerYear) == 0 ){
                   cout << tempType << endl;
                   cout << "Term:"<<tempTerm << endl;
                   cout << "Year:"<<tempYear << endl;
                   cout << tempPrepare << endl;
                   cout << tempProblems << endl;
                   cout << tempOther << endl << endl;
            }

         }
         file_in.close();
      } //end else if

      //OPTION 4 -- QUIT THE PROGRAM
      else if  (4 == playerAnswer){
         cout << "Bye!" <<  endl;
      }

      //OPTION 5 -- USER ENTERED IN AN INVALID NUMBER
      else {
         cout << "This is an invalid number." << endl;
         cout << "Please try again." << endl << endl << endl;
      }
   } while (playerAnswer != 4);


   cout << endl;
   cout << endl;
   return 0;
}//END INT MAIN()

//FUNCTIONS
bool again (){
   char playerAnswer;
   cout << "Would you like to add another event?"<<endl;
   cout << "   Y or N: ";
   cin >> playerAnswer;
   cin.ignore (100, '\n');
   playerAnswer = toupper (playerAnswer);
   cout << endl << endl;
   if ('Y' == playerAnswer)
      return true;
   else
      return false;
}

void addEvent(event& activity){
   cout << "What is the type of event you are planning?" << endl;
   cout << "   add class, submit appliication, etc: ";
   cin.get (activity.type, TYPE);
   cin.ignore(100, '\n');

   cout << "What term does it take place?" << endl;
   cout << "   fall, winter, spring, summer: ";
   cin.get (activity.term, TERM);
   cin.ignore(100, '\n');

   cout << "What year will it take place?" << endl;
   cout << "   : ";
   cin >> activity.year;
   cin.ignore(100, '\n');

   cout << "What will you need to do to prepare?" << endl;
   cout << "   buy text books, ask for references, etc: ";
   cin.get (activity.prepare, PREPARE);
   cin.ignore(100, '\n');

   cout << "Are there any Contingencies?" << endl;
   cout << "   class is full, not accecpted into program, etc."
        << endl;
   cout << "   : ";
   cin.get (activity.problems, PROBLEMS);
   cin.ignore(100, '\n');

   cout << "Additional information" << endl;
   cout << "   : ";
   cin.get (activity.other,OTHER);
   cin.ignore(100, '\n');

   cout << endl << endl;
}


