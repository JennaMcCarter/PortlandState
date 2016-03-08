//Jenna McCarter
//CS 163
//Project 1
//Name of file: assignment1.h
/*This defines what information can be found in a particular node (hint and 
likes). This file also creates the head pointers for each list. And, sets all 
the avaiable functions for College_Life
*/

#include <iostream>
#include <cstring>



//constants
const int MAX = 301; //This is the max character limit for what a hint
                     // can hold

struct node {
   char * hint; // what information a user has to suggest
   int likes;   // the number of likes a hint has
   node * next;

};

class College_Life {
   public:
      College_Life(); //constructor
      ~College_Life(); //destructor
      //Adds a hint to the list
      int Add_Hint(char temp_category[], char message[]);
      //Increases how many likes a hint has and reorganizes the list
      int Like(char temp_category[], int hint_number); 
      //display every list
      int Display();
      //display all for a particular category
      int Display(char temp_category[]); 


   private:
      //head pointer for the registering list
      node * head_registering;
      //head pointer for the materials list
      node * head_materials;
      //head pointer for the homework list
      node * head_homework;
};
