//
// Author: James Fleming
//

#include <iostream>
#include <string>
#include "list.h"

using namespace std;

void init_list(List& L) 
{
    L.Head = nullptr;
    L.Count = 0;
}

void print_list(List L)
{
    Node * cur = L.Head;

    cout << "List: ";
    while (cur != nullptr)
    {
        cout << cur->Data.ID << " ";
        cur = cur->Next;
    }
}

void push_front_list(List & L, NodeData d)
{
    NodeData * nodeData = new NodeData();
    nodeData->ID = d;
    nodeData->Priority = 1;

    Node * newN = new Node();
    newN->Data = nodeData;
    newN->Next = L.Head;

    L.Head = newN;
    L.Count++;

}