//Jenna McCarter
//CS 163
/*Project 1: this project allows a user to get hints on things they might need
to know about when going to a school. They are able to add their own hints as
well as look at hints that are already there. They can 'Like' hints and the
hints with the most 'likes will appear closer to the top of the list*/

#include "assignment1.h"
using namespace std;

void display_usermenu();
int player_choice();
void get_category (char temp_category[]);


int main () {
      //STEP 0: declare variables
      College_Life hint_app; //creates new College_Life object
      int player =0; //this is hold the choice of what the user wants to do
      char temp [MAX]; //temporary array for hint
      char temp_category [MAX]; //temporary array for category
      int error = 1;
      int number_of_hint = 0;

      //STEP 1: start the application
      while (5 != player){
         // display the user menu and recieve player response
         display_usermenu();
         player = player_choice();

         //STEP 2: allow user to add a hint
         if (1 == player) {
            cout << "Which category will this hint be under?" << endl;
            get_category(temp_category);
            cout << "Please keep your hint under " << MAX-1 << " characters" 
                 << endl;
            cout << "   Hint: ";
            cin.get(temp, MAX, '\n');
            cin.ignore(100, '\n');
            error = hint_app.Add_Hint(temp_category, temp);
         }
         //STEP 3: allow user to like a hint
         else if (2 == player){
            cout << "Which category is the hint in?" << endl;
            get_category(temp_category);
            hint_app.Display(temp_category);
            cout << "To like the hint, type in it's number" << endl;
            cout << "   Hint #: ";
            cin >> number_of_hint;
            cin.ignore (100, '\n');
            hint_app.Like(temp_category, number_of_hint);            
         }
         //STEP 4: allow user to display all hints
         else if (3 == player){
            hint_app.Display();
         }
         //STEP 5:  allow user to display hints from a certain category
         else if (4 == player){
            cout << "Which category would you like to see?" << endl;
            get_category(temp_category);
            hint_app.Display(temp_category); 
         }
         //STEP : if the user wants to quit
         else if (5 == player){
            cout << "The program has ended." << endl;
         }
         //STEP : if the player choices something that is not an option
        else {
           cout << "This is not one of the choices." << endl;
           cout << "Please try again" << endl;
           player = 0;
        }
      } // end of while loop / end of application
}

//This menu displays all possible user options
void display_usermenu(){
      cout << endl << endl;
      //list all options
      cout << "Please enter in the number of the activity you would like to"
           << " do next: " << endl;
      cout << "   1. add a hint" << endl;
      cout << "   2. like a hint" << endl;
      cout << "   3. display all hints" << endl;
      cout << "   4. display hint from a certain category" << endl;
      cout << "   5. quit" << endl;
}

//This will get the player's response
int player_choice (){
      //get the player's choice
      int player = 0;
      cout << "   activity: ";
      cin >>  player;
      cin.ignore (100, '\n');
      cout << endl << endl << endl;
      return player;
}

//will ask the user what category they would like to work with
void get_category (char temp_category[]){
            cout << "Please type in 'registering', 'materials', or 'homework'"
                 << endl;
            cout << "   category: ";
            cin.get (temp_category, MAX, '\n');
            cin.ignore (100, '\n');
}
