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
    List l;

    l.push_back("James", 1);
    l.push_back("James2", 2);
    l.push_back("James3", 3);
    l.push_back("James4", 4);

    string a;
    int b;
    l.remove(-5);

    
    return 0;
}