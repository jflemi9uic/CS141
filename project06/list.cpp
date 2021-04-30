/*list.cpp*/

//
// Author: Prof. Hummel, U. of I. Chicago, Spring 2021
// 
// Implements a one-way linked-list with optimized insertion at
// head and tail of list. The nodes contain 2 data values, a string
// and an integer.
//
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "list.h"
using namespace std;

//
// private member functions:
//

//
// inits this list then makes deep copy of other
//
// Time complexity: O(N)
//
void List::initAndDeepCopy(const List &other)
{
    // initialize the list to empty
    this->Head = nullptr;
    this->Tail = nullptr;
    this->Count = 0;
    
    Node * cur = other.Head;
    while (cur != nullptr)
    {
        this->push_back(cur->Data.Value1, cur->Data.Value2);
        cur = cur->Next;
    }
}

// 
// free the nodes in the list and resets to empty
//
// Time complexity: O(N)
//
void List::freeAndReset()
{
    Node * cur = this->Head;
    Node * prev = nullptr;

    while (cur != nullptr)
    {
        prev = cur;
        cur = cur->Next;
        delete prev;
    }

    this->Head = nullptr;
    this->Tail = nullptr;
    this->Count = 0;
}

//
// public member functions:
//

//
// default constructor
//
// Initializes the list to empty.
// 
// Time complexity: O(1)
//
List::List()
{
    this->Head = nullptr;
    this->Tail = nullptr;
    this->Count = 0;
}

//
// copy constructor
//
// Makes a deep copy of the other list into this list.
// 
// Time complexity: O(N)
//
List::List(const List &other)
{
    this->initAndDeepCopy(other);
}

//
// destructor
//
// Frees all memory related to this list, and then resets to empty.
// 
// Time complexity: O(N)
//
List::~List()
{
    this->freeAndReset();
}

//
// assignment operator (e.g. L2 = L;)
//
// Makes a deep copy of the other list into this list; since this
// list already exists, the existing elements of this list are freed
// before the copy is made.
// 
// Time complexity: O(N)
//
List &List::operator=(const List &other)
{
    if (this == &other)	// special case: check for L = L;
        return * this;	// do nothing and just return THIS object back

   	//
   	// This is different from a copy constructor, because "this" list
   	// exists and contains nodes.  So we have to free "this" list before
   	// we copy the "other" list:
   	//
    this->freeAndReset();
    this->initAndDeepCopy(other);

    return * this;	// done, return THIS object back
}

//
// size
//
// Returns the # of elements in the list.
//
// Time complexity: O(1)
//
int List::size()
{
    return this->Count;
}

//
// empty
//
// Returns true if empty, false if not.
//
// Time complexity: O(1)
//
bool List::empty()
{
    if (this->Head == nullptr) return true;
    return false;
}

//
// search
//
// Search the list for the first occurence of the string value.
// If found, its position in the list is returned. Positions are 
// 0-based, meaning the first node is position 0. If the value is
// not found, -1 is returned.
//
// Time complexity: on average O(N)
//
int List::search(string value)
{
    Node * cur = this->Head;
    int i = 0;

    while (cur != nullptr)
    {
        if (cur->Data.Value1 == value)
        {
            return i;
        }
        cur = cur->Next;
        i++;
    }
    return -1;
}

//
// retrieve
//
// Retrieve's the data from node at the given position; the list 
// remains unchanged. Positions are 0-based, meaning the first node
// is position 0. Throws an "invalid_argument" exception if the 
// position is invalid, i.e. 
// throw invalid_argument("List::retrieve: invalid position");
//
// Time complexity: on average O(N)
//
void List::retrieve(int pos, string &value1, int &value2)
{
    if (pos < 0 || pos >= this->size())
    {
        throw invalid_argument("List::insert: invalid position");
    }

    Node * cur = this->Head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->Next;
    }

    value1 = cur->Data.Value1;
    value2 = cur->Data.Value2;
}

//
// insert
//
// Inserts the given data in the list such that after
// the insertion, the value is now at the given
// position.
//
// Positions are 0-based, which means a position of 0 
// denotes the data will end up at the head of the list,
// and a position of N (where N = the size of the list)
// denotes the data will end up at the tail of the list.
// If the position is invalid, throws an exception, i.e.
// throw invalid_argument("List::insert: invalid position");
//
// Time complexity: on average O(N)
//
void List::insert(int pos, string value1, int value2)
{
    if (pos < 0 || pos >= this->size())
    {
        throw invalid_argument("List::insert: invalid position");
    }
    if (pos == 0)
    {
        Node * newN = new Node();
        newN->Data.Value1 = value1;
        newN->Data.Value2 = value2;

        newN->Next = this->Head;
        this->Head = newN;
        this->Count++;
    }
    else
    {
        Node * cur = this->Head;
        Node * prev = nullptr;

        for (int i = 0; i < pos; i++)
        {
            prev = cur;
            cur = cur->Next;
        }

        Node * newN = new Node();
        newN->Data.Value1 = value1;
        newN->Data.Value2 = value2;

        newN->Next = cur;
        prev->Next = newN;
        this->Count++;
    }
}

//
// remove
//
// Removes and deletes the node at the given position; no data is
// returned. Positions are 0-based, meaning the first node
// is position 0. Throws an "invalid_argument" exception if the 
// position is invalid, i.e. 
// throw invalid_argument("List::remove: invalid position");
//
// Time complexity: on average O(N)
//
void List::remove(int pos)
{
    if (pos < 0 || pos >= this->size())
    {
        throw invalid_argument("List::insert: invalid position");
    }
    
    if (pos == 0)
    {
        Node * first = this->Head;
        Node * second = this->Head->Next;
        delete first;
        this->Head = second;
        this->Count++;

        return;
    }

    Node * cur = this->Head;
    Node * prev = nullptr;

    for (int i = 0; i < pos; i++)
    {
        prev = cur;
        cur = cur->Next;
    }

    // at this point cur is the node that we want to delete and prev is the node before
    Node * temp = cur->Next;
    if (temp == nullptr) // the last node is being removed
    {
        prev->Next = nullptr;
        delete cur;
        this->Tail = prev;
    }
    else // deleting a node that is in the middle of the list
    {
        prev->Next = temp;
        delete cur;
    }
    this->Count--;
}

//
// front
//
// Returns the data from the first node in the list. Throws an 
// exception if the list is empty, i.e.
// throw runtime_error("List::front: empty list");
// 
// Time complexity: O(1)
//
void List::front(string &value1, int &value2)
{
    Node * cur = this->Head;

    if (cur == nullptr)
    {
        throw runtime_error("List::front: empty list");
    }
    value1 = cur->Data.Value1;
    value2 = cur->Data.Value2;
}

//
// back
//
// Returns the data from the last node in the list. Throws an 
// exception if the list is empty, i.e.
// throw runtime_error("List::back: empty list");
// 
// Time complexity: O(1)
//
void List::back(string &value1, int &value2)
{
    Node * cur = this->Tail;

    if (cur == nullptr)
    {
        throw runtime_error("List::front: empty list");
    }
    value1 = cur->Data.Value1;
    value2 = cur->Data.Value2;
}

//
// push_front
//
// Inserts the given data at the front of the list.
// 
// Time complexity: O(1)
//
void List::push_front(string value1, int value2)
{
    Node * newN = new Node();
    newN->Data.Value1 = value1;
    newN->Data.Value2 = value2;

    if (this->size() == 0)
    {
        newN->Next = this->Head;
        this->Head = newN;
        this->Tail = newN;
        this->Count++;
    }
    else
    {
        newN->Next = this->Head;
        this->Head = newN;
        this->Count++;
    }
}

//
// push_back
//
// Inserts the given data at the back of the list.
// 
// Time complexity: O(1)
//
void List::push_back(string value1, int value2)
{
    Node * newN = new Node();
    newN->Data.Value1 = value1;
    newN->Data.Value2 = value2;

    if (this->size() == 0)
    {
        this->Head = newN;
        this->Tail = newN;
        newN->Next = nullptr;
        this->Count++;
    }
    else
    {
        this->Tail->Next = newN;
        newN->Next = nullptr;
        this->Tail = newN;
        this->Count++; 
    }
}

//
// print
//
// prints the list for testing purposes
//
void List::print()
{
    Node * cur = this->Head;

    while (cur != nullptr)
    {
        cout << cur->Data.Value1 << " ";
        cur = cur->Next;
    }
    cout << endl;
}