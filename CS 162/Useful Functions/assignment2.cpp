//Jenna McCarter
// CS 162
//This program  creates different functions that will change an array with only
  //using the <iostream> library
//The algorithm is with the second file.

#include <iostream>
using namespace std;

   //PROTOTYPES
   void makeLower (char sampleArray[]);
   void readArray(char sampleArray[]);
   void display (char sampleArray[]);
   void firstLetter (char sampleArray[]);
   void everyWord (char sampleArray[]);
   void everyLetter (char sampleArray[]);
   void everySentence (char sampleArray[]);
   bool compareArray (char sampleArray[], char secondArray[]); 

  //CONSTANTS
   const int MAX = 50; // amount in sampleArray
   const int CAP = 32; // amount needed to capitalize a letter in ascii

  //INT MAIN
int main () {
   char sampleArray [MAX];
   char secondArray [MAX];

   readArray(sampleArray);
   display (sampleArray);
   cout << "makes everything lowercase." << endl;
   makeLower (sampleArray);
   display (sampleArray);
   cout << "capitalizes first letter of an array" << endl;
   firstLetter (sampleArray);
   display (sampleArray);
   cout << "capitalizes first letter in each word"<<endl;
   everyWord (sampleArray);
   display (sampleArray);
   cout << "capitalizes every letter"<< endl;
   everyLetter (sampleArray);
   display (sampleArray);
   cout << "capitalizes start of a sentence" << endl;
   everySentence (sampleArray);
   display (sampleArray);
   cout << "compares two arrays" << endl;
   readArray (secondArray);
   display (secondArray);
   if ( compareArray (sampleArray, secondArray))
      cout << "The arrays match."<< endl;
   else
      cout << "The arrays do not match."<< endl;
   cout << endl;
   return 0;
}

   //FUNCTIONS
   //makes sure every letter is lowercase, if not, changes letter
   void makeLower (char sampleArray[]){
      int i = 0; //index
      while (sampleArray[i] != '\0') {
         if (sampleArray[i]>= 65 && sampleArray[i] <= 90)
            sampleArray[i] += CAP;
         ++i;
      }
   }

   //reads in user's array
   void readArray (char sampleArray[]) {
      //Fills array with \0
      for (int i =0; i<MAX; i++)
         sampleArray [i] = '\0';
      cout << "Please enter in a statement: ";
      cin.get (sampleArray, MAX, '\n');
      cin.ignore(100,'\n');
   }

   //displays user's array
   void display (char sampleArray[]) {
      cout << "Your sentence reads: " << endl;
      cout << sampleArray << endl;
      cout << endl;
   }


   //capitalizes first letter of an array
   void firstLetter (char sampleArray[]){
      makeLower (sampleArray);
      //makes sure is a letter and then capitalizes it
      if (sampleArray[0]  >= 97 && sampleArray [0] <=122){
         sampleArray[0] -= CAP;
      }
   }

   //capitalizes first letter in each word
   void everyWord (char sampleArray[]){
      makeLower (sampleArray);
      int i = 0; //index
      while (sampleArray[i] != '\0'){
         if (0 == i && sampleArray[i]  >= 97 && sampleArray [i] <=122)
            sampleArray[i] -= CAP;
         else if (' ' == sampleArray[i]){
            do {
               i++;
               if (sampleArray[i]  >= 97 && sampleArray [i] <=122)
                  sampleArray[i] -= CAP;
            } while (sampleArray[i] <65 || sampleArray[i] >90);
         }
         ++i;
      }
   }

   //capitalizes every letter
   void everyLetter (char sampleArray[]){
      makeLower (sampleArray);
      int i = 0; //index
      while (sampleArray[i] != '\0'){
         if (sampleArray[i]  >= 97 && sampleArray [i] <=122)
            sampleArray[i] -=CAP;
         ++i;
      }
   }

   //capitalizes first letter after a period, exclamation mark, or question mark
   void everySentence (char sampleArray[]){
      makeLower (sampleArray);
      int i = 0; //index
      while (sampleArray[i] != '\0'){
         if (0 ==i)
            sampleArray[0] -= CAP;
         else if ('.' == sampleArray[i] || '!' == sampleArray[i] ||
             '?' == sampleArray[i]){
            do {
               if (' ' == sampleArray[i])
                  ++i;
               else if (sampleArray[i]  >= 97 && sampleArray [i] <=122)
                  sampleArray[i] -=CAP;
               else
                  ++i;
            }while (sampleArray[i]  < 65 ||  sampleArray [i] > 90); //do
         } //if
         ++i;
      } //while
   } //void


   //compares two arrays
   bool compareArray (char sampleArray[], char secondArray[]){
      makeLower (sampleArray);
      makeLower (secondArray);
      int i =0; //index
      bool isMatching = false;
      do {
         if (sampleArray[i] == '\0' && secondArray[i] == '\0'){
            return true;
         }
         else if (sampleArray[i] == secondArray[i])
            ++i;
         else{
            return false;
         }
      } while (sampleArray != '\0');

   }
