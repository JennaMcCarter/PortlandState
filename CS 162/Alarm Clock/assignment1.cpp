//Jenna McCarter
//This program allows you to set an alarm, change the alarm time by adding or
// subtracting, and turn on or off the alarm 

#include <iostream>
#include <cctype>
using namespace std;

   // Asks user for hour input
   int setHours (int hours) {
      cout << "What time would you like to set your alarm?"<< endl;
      cout << "   Please use military time." << endl;
      cout << "   Hours: ";
      cin >> hours;
      cin.ignore (100, '\n');
      return hours;
   }
 
   //Asks user for minute input
   int setMinutes (int minutes) {
      cout << "   Minutes: ";
      cin >> minutes;
      cin.ignore (100, '\n');
      return minutes;
   }

   // confirms if this is what the user wants
   bool isCorrect (bool isCorrectResponse) {
      if (isCorrectResponse == true){
         char answer = 'N';
         cout << "   Is this correct? Y/N: ";
         cin >> answer;
         cin.ignore (100, '\n');
         answer = toupper (answer);
         if (answer == 'Y')
            return true;
         cout << endl;
         return false;
      }
      else {
         return false;
      }
   }

   //If the user inputs 05 for minutes, will display like this instead of 5
   void formatTime (int number){
     // cout << "number: " << number << endl;
      if (number <10){
         cout << "0" << number;
      }
      else {
         cout << number;
      }
   }

   //corrects the numbers so it reads as a clock
   int correctTime (int& hours, int& minutes, int& seconds){
      int holdTime = 0; // variable to hold extra time to carry over
      if (seconds > 59){
         holdTime = seconds/60;
         seconds %= 60;
         minutes += holdTime;
      }
      if (minutes > 59) {
         holdTime = minutes / 60;
         minutes %= 60;
         hours += holdTime;
      }
      if (hours > 24) {
         holdTime = hours%24;
         hours = holdTime;
      }
      if (seconds <0){
         seconds *= -1;
         holdTime = (seconds/60);
         seconds = (seconds%60);
         minutes -= holdTime;
      }
      if (minutes <0) {
         minutes *= -1;
         holdTime = (minutes/60);
         minutes = (minutes%60);
         hours -= holdTime;
      }
      if (hours <0) {
         hours *= -1;
         holdTime = hours%24;
         hours = 24 - holdTime;
      }
      if (0 == hours) {
         hours = 24;
      }
      return hours, minutes, seconds;
   }

   // Asks user what they will like to do next
   int nextStep (int playerResponse) {
      do {
         cout << "      Enter 1 to change the time." << endl;
         cout << "      Enter 2 to turn alarm on or off." << endl;
         cout << "      Enter 3 to quit." << endl;
         cout << "   Response: ";
         cin >> playerResponse;
         cin.ignore (100, '\n');

         if (playerResponse <1 || playerResponse >3){
            cout << "   You have picked an incorrect number." << endl;
            cout << "   Please try again." << endl;
         }
      } while (playerResponse < 1 || playerResponse >3);
      return playerResponse;
   }

   // Allows the user to turn on and off the alarm
   bool turnOnOrOffAlarm (){
      int playerResponse = 0;
      do {
         cout << "      Enter 1 to turn on your alarm." << endl;
         cout << "      Enter 2 to turn off your alarm." << endl;
         cout << "      Response: ";
         cin >> playerResponse;
         cin.ignore (100, '\n');
         cout << endl;
         if (playerResponse <1 || playerResponse >2){
            cout << "   You have entered in an incorrect value." << endl;
            cout << "   Please try again." << endl;
         }
         else if (1 == playerResponse){
            cout << "   You have turned on your alarm." << endl;
            return true;
         }
         else {
            cout << "   You have turned off your alarm." << endl;
            return false;
         }
      } while (playerResponse < 1 || playerResponse >2);
   }

   //asks user for input for time
   int askForNumber () {
       int playerResponse;
       cin >> playerResponse;
       cin.ignore (100, '\n');
       return playerResponse;
   }

   //calculates how much is added or subtracted
   int calculateRevision (int& hours, int& minutes, int& seconds) {
      int playerResponse = 0;
      int hr, min, sec = 0; // change in time
      do {
         cout << "      Enter 1 to add time." << endl;
         cout << "      Enter 2 to subtract time." << endl;
         cout << "   Response: ";
         cin >> playerResponse;
         cin. ignore (100, '\n');
         if (playerResponse < 1 || playerResponse >2){
            cout << "You have entered in an invalid number."<< endl;
            cout << "Please try again." << endl;
         }
         else {
            cout << "   please enter how much you would like to change." << endl;
            cout << "   Hours: ";
            hr = askForNumber();
            cout << "   Minutes: ";
            min = askForNumber();
            cout << "   Seconds: ";
            sec = askForNumber();
 
            if (1 == playerResponse ){
               seconds += sec;
               minutes += min;
               hours += hr;
            }
            else {
              seconds -= sec;
              minutes -= min;
              hours -= hr;
            }
            correctTime (hours, minutes, seconds);
         }//end adding or subtracting
      } while (playerResponse < 1 || playerResponse >2);
   }



int main () {
   // STEP 0: declare variables
   int hours, minutes, seconds = 0;
   bool isCorrectResponse = false; //makes sure the user puts in the right
                                   // response before program continues
   bool isAlarmSet = false;  // determines is alarm is set
   bool isQuitting = false;  //determines if player wants to stop program
   int playerResponse = 0; // decides what the player wants to do next


   //STEP 1: set time
   do {
      hours = setHours (hours);
      minutes = setMinutes (minutes);
      cout << endl;

      //STEP 2 & 3: confirm time
      if (hours < 0 ||  minutes < 0 || seconds < 0){
         cout << "   You have entered in an incorrect time." << endl;
         cout << "   Please try again." << endl;
         isCorrectResponse = false;
      }
      else { 
         correctTime (hours, minutes, seconds);
         cout << "   You have entered in ";
         formatTime(hours);
         cout  << ":";
         formatTime (minutes);
         cout << "." << endl;
         isCorrectResponse = true;
      }
   } while (!isCorrect(isCorrectResponse));
   isAlarmSet = true;
   cout << "Your alarm is now set!" << endl;

   //STEP 4: calculate revision and display
   do {
      cout << "What would you like to do next?" << endl;
      playerResponse =  nextStep(playerResponse);
       
      if (3 == playerResponse){
         isQuitting = true;
      }
      else if (2 == playerResponse) {
         cout << "Would you like to turn on or off your alarm?" << endl;
         isAlarmSet = turnOnOrOffAlarm(); 
      }
      else if (1 == playerResponse) {
         cout << "Would you like to add or subtract time?" << endl;
         calculateRevision (hours, minutes, seconds);
         cout << "   Your alarm time is now ";
         formatTime (hours);
         cout  << ":";
         formatTime (minutes);
         cout << ":";
         formatTime (seconds);
         cout  << "." << endl;
      } 

   } while (false  == isQuitting);

} // END MAIN() 

