/*student.cpp*/

#include <iostream>
#include "student.h"

using namespace std;


//
// copy constructor:
//
Student::Student(const Student& other)
{
    // this is the copy of other
   this->Netid = other.Netid;
   this->Head = nullptr;

   Node * cur = other.Head;

   while (cur != nullptr)
   {
       this->push_back(cur->Grade);
       cur = cur->Next;
   }
}


//
//
// push_back (private helper function)
//
// Adds the grade to the end of this linked-list.
//
void Student::push_back(string grade)
{
   //
   // allocate a new node to store the grade:
   //
   Node* newN = new Node();
   newN->Grade = grade;
   newN->Next = nullptr;
   
   //
   // traverse to last node to insert at the end:
   //
   Node* cur = this->Head;
   Node* prev = nullptr;

   while (cur != nullptr)
   {
      prev = cur;
      cur = cur->Next;
   }

   //
   // link after prev:
   //
   if (prev == nullptr)  // update head:
   {
      this->Head = newN;
   }
   else  // link after prev (the last node):
   {
      prev->Next = newN;
   }
}


//
// constructor:
//
Student::Student(string netid)
{
   this->Netid = netid;
   this->Head = nullptr;
}


//
// destructor:
//
Student::~Student()
{
   Node* cur = this->Head;
   
   while (cur != nullptr)  // free the nodes:
   {
      Node* temp = cur->Next;
      delete cur;
      cur = temp;
   }
   
   this->Head = nullptr;  // reset to empty:
}


//
// add:
//
// Adds the grade to the student's list of grades.
//
void Student::add(string grade)
{
   this->push_back(grade);
}


//
// getNetid:
//
// Returns the student's Netid.
//
string Student::getNetid()
{
   return Netid;
}


//
// getGrade
//
// Returns ith grade in the list.
//
string Student::getGrade(int i)
{
   if (i < 0)
     return "";

   Node* cur = this->Head;

   while (cur != nullptr)
   {
      if (i == 0)
        return cur->Grade;

      i--;
      cur = cur->Next;
   }

   // if get here, i not valid:
   return "";
}


//
// size
//
int Student::size()
{
   int count = 0;

   Node* cur = this->Head;

   while (cur != nullptr)
   {
      count++;
      cur = cur->Next;
   }

   return count;
}

