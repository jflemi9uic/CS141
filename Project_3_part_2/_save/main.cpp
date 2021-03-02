/*main.cpp*/

//
// James Fleming
//

#include <iostream>
#include <string>

#include "token.h"

using namespace std;

struct Variable {
    string Name;
    string Value;
    string Type;
}

int main(int argc, char* argv[])
{
   // 
   // 1. process command-line args:
   //
   // argv[0]: ./main
   // argv[1]: filename.py
   // argv[2]: memorysize
   //
   if (argc != 3)
   {
      cout << "usage: ./main filename.py memorysize" << endl;
      return 0;
   }

   string filename(argv[1]);  // this is your SimplePy program file
   int    MemorySize = stoi(argv[2]);  // this is size for Memory array


   //
   // TODO: call inputSimplePy to input the SimplePy program, and
   // you'll get back an array of Tokens.  Allocate another array
   // for your memory, and then start executing!
   //
   cout << filename << endl;    // delete these eventually
   cout << MemorySize << endl;


   return 0;
}
