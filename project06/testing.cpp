//
// 
// testing for part 2
//
//
#include <iostream>
#include <string>
#include "list.h"

using namespace std;


int main()
{
    List L, L2, L3;
    
    int val2, pos;
    string val1;
    
    try
    {
        cout << "Empty or not: " << L.empty() << endl;  // outputs 1 for false
        L.push_front("hello", 1);
        L.push_back("world", 2);
        L.push_back("happy", 3);
        L.insert(0, "spring", 4);

        cout << "Empty or not: " << L.empty() << endl;  // outputs 1 for false
        L3 = L;
        
        cout << "Empty or not: " << L3.empty() << endl;  // outputs 1 for false
        L3.push_back("q", 8);
        L3.push_back("m", 9);
        L3.push_front("a", 10);
        
        cout << "Empty or not: " << L3.empty() << endl;  // outputs 1 for false
        for (int i = 0; i < L.size(); i++)
        {
            L.retrieve(i, val1, val2);
            cout << val1 << " " << val2 << " ";
        }
        cout << endl;
        
        cout << "Count: " << L.size() << endl;
        
        L.front(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        L.back(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        for (int i = 0; i < L3.size(); i++)
        {
            L3.retrieve(i, val1, val2);
            cout << val1 << " " << val2 << " ";
        }
        cout << endl;
        cout << "Count: " << L3.size() << endl;
        
        L3.front(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        L3.back(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        for (int i = 0; i < L.size(); i++)
        {
            L.retrieve(i, val1, val2);
            cout << val1 << " " << val2 << " ";
        }
        cout << endl;
        cout << "Count: " << L.size() << endl;
        
        L.front(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        L.back(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        
        cout << "Empty or not: " << L2.empty() << endl;  // outputs 1 for false
        L2.push_front("hey", 5);
        L2.push_back("hi", 6);
        L2.push_back("good", 7);
        
        cout << "Empty or not: " << L2.empty() << endl;  // outputs 1 for false
        for (int i = 0; i < L2.size(); i++)
        {
            L2.retrieve(i, val1, val2);
            cout << val1 << " " << val2 << " ";
        }
        cout << endl;
        cout << "Count: " << L2.size() << endl;
        
        L2.front(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        L2.back(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        L3 = L2;    // this list is L3 and make a deepy copy of the other list L2 into L3 which is empty and not initialized

        cout << "Empty or not: " << L3.empty() << endl;  // outputs 1 for false
        L3.remove(2);
        L3.push_back("q", 8);
        L3.push_back("m", 9);
        L3.push_front("a", 10);
        L3.remove(4);
        
        cout << "Empty or not: " << L3.empty() << endl;  // outputs 1 for false
        pos = L3.search("q");
        
         cout << "Position: " << pos << endl;
        
        for (int i = 0; i < L3.size(); i++)
        {
            L3.retrieve(i, val1, val2);
            cout << val1 << " " << val2 << " ";
        }
        cout << endl;
        cout << "Count: " << L3.size() << endl;
        
        
        L3.front(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        L3.back(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        for (int i = 0; i < L2.size(); i++)
        {
            L2.retrieve(i, val1, val2);
            cout << val1 << " " << val2 << " ";
        }
        cout << endl;
        cout << "Count: " << L2.size() << endl;
        
        
        L2.front(val1, val2);
        cout << val1 << " " << val2 << endl;
        
        L2.back(val1, val2);
        cout << val1 << " " << val2 << endl;
    
    }
    catch (invalid_argument& e)
    {
        
    }

    
    return 0;
}