//Jenna McCarter
// CS 163
//Project 1
//Name of file: assignment.cpp
/*This file contains all the function definitions for College_life as well as
the local functions.
*/ 

#include "assignment1.h"
using namespace std;

void add_to_end (node * & current, node * & temp);
void display_list (node * head);
int find_hint (node * & current, node * & previous, int hint_number);
int organizes_likes (node * & current, node * & previous, node * & head);


//Constructor
//Sets all values to NULL
College_Life::College_Life(){

      //set default values
      head_registering = NULL;
      head_materials = NULL;
      head_homework = NULL;
}

//will recieve information from the user for two sets of character strings.
// one will be what category they want to put the hint in and what the hint is.
//it will store the hint in the right category by placing it at the end 
//of the right LL. If the category is not typed in correctly, this will return 
//a 0.
int College_Life::Add_Hint (char temp_category[], char message[]){

      //STEP 1: decide what catagory the hint is being placed
      //STEP 2: add hint to the right list
      
      //deallocate memory
      node * temp = new node;
      temp->hint = new char [strlen(message)+1];
      strcpy (temp->hint,message);      
      temp->likes = 0;

      char * category = new char [strlen(temp_category)+1];
      strcpy (category, temp_category);

      //category: registering
      if (strcmp (category, "registering") == 0){
         //create current pointer
         node * current = head_registering;
         //if head is NULL
         if (!head_registering){
            head_registering = temp;
            head_registering ->next= NULL;
         }
         //if there is at least one node
         else {
            add_to_end(current, temp);
         }
      }
      //category: materials
      else if (strcmp (category, "materials") == 0){
         //create current pointer
         node * current = head_materials;
         //if head is NULL
         if (!head_materials){
            head_materials = temp;
            head_materials -> next = NULL;
         }
         //if there is at least one node
         else {
            add_to_end(current, temp);
         }
      }
      //category: homework
      else if (strcmp (category, "homework") == 0){
         //create a current pointer
         node * current = head_homework;
         //if head is NULL
         if (!head_homework){
            head_homework = temp;
            head_homework -> next = NULL;
         }
         //if there is at least one node
         else {
            add_to_end(current, temp);
         }
      }
      else{
         //if the category does not match up
         return 0;
      }
}

//This function takes in the node that is being placed in the list and a pointer
// that points to head (current), and adds it to the end of the LL
//This does not have any output
void add_to_end (node * & current, node * & temp){
   while(current->next){
      current = current->next;
   }
   current->next = temp;
   temp->next = NULL;
}

//This function requires what category it is working with and what hint
//Then, it can add a like and then sort the list based on the number
// of likes. 
//If there is an error inputing the category, it returns 0
//If adding the hint is sucessful, it returns 1
int College_Life::Like(char temp_category[], int hint_number){
      //find hint in list
      node * current;
      node * previous;
      node * head;

      char * category = new char [strlen(temp_category)+1];
      strcpy (category, temp_category);

      if (strcmp (category, "registering") == 0){
         current = head_registering;
         find_hint (current, previous, hint_number);
         head = head_registering;
         organizes_likes (current, previous, head);
         head_registering = head;
         return 1;
      }
      else if (strcmp (category, "materials") == 0) {
         current = head_materials;
         find_hint (current, previous, hint_number);
         head = head_materials;
         organizes_likes (current, previous, head);
         head_materials = head;
         return 1;
      }
      else if (strcmp (category, "homework") == 0) {
         current = head_homework;
         find_hint (current, previous, hint_number);
         head = head_homework;
         organizes_likes (current, previous, head);
         head_homework = head;
         return 1;
      }
      else
         return 0;
}

//This function finds the node that has been given a likes based on the number 
//entered and adds a like to that hint
//If they type in a value for a hint that is not available, it return a 0
int find_hint (node * & current, node * & previous, int hint_number){
     if (!current)
        return 0;
     else if (!current->next || hint_number == 1){
        ++current->likes;
        cout << "A like has been added" << endl;
        previous = NULL;
     }
     else {
        int count = 1;
        previous = current;
        current = current->next;
        ++count;
        while (count < hint_number && current->next){
           previous = previous->next;
           current = current->next;
           ++count;
        }
        if (hint_number == count){
           cout << "A like has been added" << endl;
           ++current->likes;
        }
        else
           return 0;
     }     
}

//This function organizes the list based on where the hint is from find_hint
//This function returns a 0 if an error has been found and a 1 if there is
//not an error 
int organizes_likes (node * & current, node * & previous, node * & head){
      //temp = node being moved, current = moves through list
      node * temp = current;
      
      //seperate node (with temp) that from the rest of the list
         //there are zerso nodes
         if (!head)
            return 0;
         //there is one node
         else if(!current->next)
            return 1;
         //current is already at the front of the list
         else if (current == head)
            return 1;
         //temp is in the middle of the list
         else if (current->next){
            current = current->next;
            previous->next = current;
         }
         //temp is at the end of the list
         else if (!current->next){
            previous ->next = NULL;
         }



      //find where temp goes in the list
         current = head;
         previous = head;
         current = current -> next;
         
         //move through the list
         do {
            //move temp to the front of the list
            if (head->likes < temp->likes){
               cout << "likes: FRONT" << endl;
               temp ->next = head;
               head = temp;
               return 1;
            }

            //move temp to the middle of the list
            else if (temp->likes <= previous->likes && 
                     temp->likes > current->likes){
               cout << "likes: MIDDLE" << endl;
               previous->next = temp;
               temp->next = current;
               return 1;
            }
         
            //temp stays at the end
            else if (current->likes >= temp->likes){
               cout << "likes: END" << endl;
               current->next = temp;
               temp->next = NULL;
               return 1;
            }
         
            if (current->next){
               current= current->next;
               previous = previous->next;
            }

         } while (current->next);
}

//This displays all hints regardless of category.
//If there is not anything that can be displayed, it returns a 0
//If it works, it returns a 1
int College_Life::Display(){

      //check if head == NULL
      if (!head_registering)
         return 0;
      else {
         if (head_registering){
            cout << "category: registering: " << endl;
            display_list (head_registering);
            return 1;
         }
         if (head_materials){
            cout << "category: materials: " << endl;
            display_list (head_materials);
            return 1;
         }
         if (head_homework) {
            cout << "category: homework: " << endl;
            display_list (head_homework);
            return 1;
         }
      }

}

//This function is given the start of the list and will display the contents
//of the list.
//This does not return anything
void display_list (node * head){
         int count = 1;
         if (head){
            cout << "   " << count << ". "  << head->hint << endl;
            cout << "         likes: " << head->likes << endl; 
            while (head->next){
               head = head->next;
               ++count;
               cout << "   " << count << ". " << head->hint << endl;
               cout << "         likes: " << head->likes << endl;
            }
         }
}


//This function displays the list based on which category the user wants
//to see. If there is an error, it returns a 0
//If it works, it returns a 1
int College_Life::Display(char temp_category[]){

      //STEP 1:
      char * category = new char [strlen(temp_category)+1];
      strcpy (category, temp_category);

      if (strcmp (category, "registering") == 0){
         display_list (head_registering);
         return 1;
      }
      else if (strcmp (category, "materials") == 0) {
         display_list (head_materials);
         return 1;
      }
      else if (strcmp (category, "homework") == 0) {
         display_list (head_homework);
         return 1;
      }
      else
        return 0;
}

//Destructor
//Deallocates all memory
College_Life::~College_Life(){
      //head_registering
      if (head_registering){
         node * temp = head_registering;
         if (!head_registering->next){
            delete head_registering;
            head_registering = NULL;
         }
         else {
               temp = temp->next;
               delete head_registering;
               head_registering = temp;
            while (head_registering->next){
               temp = temp->next;
               delete head_registering;
               head_registering = temp;
            }
         }
      }
      //head_materials
      if (head_materials) {
         node * temp = head_materials;
         if (!head_materials->next){
            delete head_materials;
            head_materials = NULL;
         }
         else {
               temp = temp->next;
               delete head_materials;
               head_materials = temp;
            while (head_materials->next){
               temp = temp->next;
               delete head_materials;
               head_materials = temp;
            }
         }
      }
      //head_homework
      if (head_homework) {
         node * temp = head_homework;
         if (!head_homework->next){
            delete head_homework;
            head_homework = NULL;
         }
         else {
               temp = temp->next;
               delete head_homework;
               head_homework = temp;
            while (head_homework->next){
               temp = temp->next;
               delete head_homework;
               head_homework = temp;
            }
         }
      }
}



