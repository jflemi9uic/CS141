#include "list.h"
#include <iostream>
#include <fstream>
 

int main(){
string filename;
    
    List test;
    

    
    string t1; 
    int t2; 
    
    //TESTING FRONT
    
    cout << "TESTING FRONT: expect krabs, plankton, neptune" << endl; 
    
    test.push_front("krabs", 2);
    
    test.front(t1, t2);
    cout << t1 << " " << t2 << endl; 
    
    test.push_front("plankton", 3);
    
    test.front(t1, t2);
    cout << t1 << " " << t2 << endl; 
    
    test.push_front("neptune", 7);
    
    test.front(t1, t2);
    cout << t1 << " " << t2 << endl << endl; 
    
    
    //TESTING BACK
    cout << "TESTING BACK: expect wumbo, star, puff" << endl; 
    
    test.push_back("wumbo", 24);
    
    test.back(t1, t2);
    cout << t1 << " " << t2 << endl; 
    
    test.push_back("star", 25);
    
    test.back(t1, t2);
    cout << t1 << " " << t2 << endl; 
    
    test.push_back("puff", 30);
    
    test.back(t1, t2);
    cout << t1 << " " << t2 << endl << endl; 
    
    //TESTING REMOVE
    
    List test2;
    
    test2.push_back("krabs", 2);
    test2.push_back("plankton", 3);
    test2.push_back("puff", 30);
    test2.push_back("star", 25);
    
    cout << "TESTING REMOVING BACK: expect puff" << endl;
    test2.remove(3);
    test2.back(t1, t2);
    cout << t1 << " " << t2 << endl << endl; 
    
    cout << "TESTING REMOVING FRONT: expect plankton" << endl;
    test2.remove(0);
    test2.front(t1, t2);
    cout << t1 << " " << t2 << endl << endl;
    
    //TESTING Retrieve
    cout << "TESTING RETRIEVE: expect larry, spongebob, squidward, sandy " << endl;
    List test3;
    
    test3.push_back("larry", 2);
    test3.push_back("sandy", 3);
    test3.push_back("squidward", 30);
    test3.push_back("spongebob", 25);
    
    test3.retrieve(0, t1, t2);
    cout << t1 << " " << t2 << endl;
    test3.retrieve(3, t1, t2);
    cout << t1 << " " << t2 << endl;
    test3.retrieve(2, t1, t2);
    cout << t1 << " " << t2 << endl;
    test3.retrieve(1, t1, t2);
    cout << t1 << " " << t2 << endl;
   
    
    return 0;
}