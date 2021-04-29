//
// Author: James Fleming UIC Spring 2021
//
// class enrollment program that allows interaction with 5 classes. Students 
//     are allowed to be enrolled, waitlisted, and users are able to see 
//     information about the classes
// 

#include <iostream>
#include <string>
#include <fstream>
#include "classreg.h"

using namespace std;

void execute(ClassReg classes[], string command);
void processPrompt(istream & input, bool keyboard, ClassReg classes[]);
void sort(string students[], int numStudents);

void helpCommand()
{
    cout << "stats" << endl;
    cout << "list class" << endl;
    cout << "increase class capacity" << endl;
    cout << "enroll class netid" << endl;
    cout << "waitlist class netid priority" << endl;
    cout << "process filename" << endl;
    cout << "output filename" << endl;
    cout << "quit" << endl;
    cout << endl;
}

void statsCommand(ClassReg classes[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << classes[i].getName() << ": enrolled=" << classes[i].numEnrolled() 
            << ", waitlisted=" << classes[i].numWaitlisted() << endl;
    }

    cout << endl;
}

void listCommand(ClassReg classes[], istream & input)
{
    bool found = false;
    string c;
    input >> c;

    for (int i = 0; i < 5; i++)
    {
        if (c == classes[i].getName())
        {
            found = true;

            // print name and capacity
            cout << classes[i].getName() << endl;
            cout << "Capacity: " << classes[i].getCapacity() << endl;

            // enrolled students -- NEED TO BE SORTED -- 
            cout << "Enrolled (" << classes[i].numEnrolled() << "): ";
            // create dynamically allocated array to sort for output
            string * students = new string[classes[i].numEnrolled()];
            // insert students into the DAA
            for (int q = 0; q < classes[i].numEnrolled(); q++)
            {
                string netid = classes[i].retrieveEnrolledStudent(q);
                students[q] = netid;
            }

            sort(students, classes[i].numEnrolled());

            for (int q = 0; q < classes[i].numEnrolled(); q++)
            {
                cout << students[q] << " ";
            }
            cout << endl;

            delete[] students;

            // waitlisted students are in the pqueue
            cout << "Waitlisted (" << classes[i].numWaitlisted() << "): ";
            for (int q = 0; q < classes[i].numWaitlisted(); q++)
            {
                // get the student
                string studentName;
                int studentPriority;
                classes[i].retrieveWaitlistedStudent(q, studentName, studentPriority);

                cout << studentName << " (" << studentPriority << ") ";
            }
            cout << endl;
        }
    }

    if (!found) cout << "**Invalid class name, try again..." << endl;

    cout << endl;
}

void increaseCommand(ClassReg classes[], istream & input)
{
    bool found = false;
    string className;
    int newCapacity;
    input >> className >> newCapacity;

    for (int i = 0; i < 5; i++)
    {
        if (className == classes[i].getName())
        {
            found = true;
            if (newCapacity < classes[i].getCapacity()) cout << "**Error, cannot decrease class capacity, ignored..." << endl;
            else
            {
                classes[i].setCapacity(newCapacity);

                cout << classes[i].getName() << endl;
                cout << "Capacity: " << classes[i].getCapacity() << endl;
            }
        }
    }

    if (!found) cout << "**Invalid class name, try again..." << endl;

    cout << endl;
}

void enrollCommand(ClassReg classes[], istream & input)
{
    bool found = false;

    string className, netid;
    input >> className >> netid;

    for (int i = 0; i < 5; i++)
    {
        if (className == classes[i].getName())
        {
            found = true;
            if (classes[i].searchEnrolled(netid) != -1) 
            {
                cout << "Student '" << netid << "' enrolled in " << className << endl;
                cout << endl;
                return; // already enrolled, do nothing
            }
            
            // not enrolled, maybe on waitlist?
            int inPqueue = classes[i].searchWaitlisted(netid);
            if (inPqueue != -1) // in waitlist
            {
                if (classes[i].numEnrolled() < classes[i].getCapacity()) // room in the class
                {
                    // remove from waitlist and enroll
                    classes[i].removeWaitlistedStudent(inPqueue);
                    classes[i].enrollStudent(netid);
                    cout << "Student '" << netid << "' enrolled in " << className << endl;
                    cout << endl;
                    return;
                }
                else // no room in the class but theyre already in the waitlist, do nothing
                {
                    cout << "Class full, '" << netid << "' waitlisted for " << className << endl;
                    cout << endl;
                    return;
                }
            }
            else // not in the waitlist AND not enrolled
            {
                // try enroll
                if (classes[i].numEnrolled() < classes[i].getCapacity()) // room in the class
                {
                    classes[i].enrollStudent(netid);
                    cout << "Student '" << netid << "' enrolled in " << className << endl;
                    cout << endl;
                    return;
                }
                else
                {
                    // no room in the class, get the priority of the last element
                    string waitlistNetid;
                    int waitlistPriority;
                    try
                    {
                        classes[i].retrieveWaitlistedStudent(classes[i].numWaitlisted() - 1, waitlistNetid, waitlistPriority);
                        classes[i].waitlistStudent(netid, waitlistPriority);

                        cout << "Class full, '" << netid << "' waitlisted for " << className << endl;
                        cout << endl;
                        return;
                    }
                    catch (exception & e)
                    {
                        waitlistNetid = netid;
                        waitlistPriority = 1;
                    }
                    
                    // waitlist the student
                    classes[i].waitlistStudent(waitlistNetid, waitlistPriority);
                    cout << "Class full, '" << netid << "' waitlisted for " << className << endl;
                    cout << endl;
                    return;
                }
            }
        }
    }

    if (!found) cout << "**Invalid class name, try again..." << endl;
    cout << endl;
}

void waitlistCommand(ClassReg classes[], istream & input)
{
    bool found = false;
    string className, netid;
    int priority;
    input >> className >> netid >> priority;

    for (int i = 0; i < 5; i++)
    {
        if (className == classes[i].getName())
        {
            found = true;
            if (classes[i].searchEnrolled(netid) != -1) 
            {
                cout << "Student '" << netid << "' enrolled in " << className << endl << endl;
                return; // already enrolled, do nothing
            }

            if (classes[i].searchWaitlisted(netid) != -1) // already waitlisted, redo priority
            {
                string name;
                int pri;
                classes[i].retrieveWaitlistedStudent(classes[i].searchWaitlisted(netid), name, pri);

                classes[i].waitlistStudent(netid, priority);
                cout << "Student '" << netid << "' waitlisted for " << className << endl;
            }
            else
            {
                // not already waitlisted, put that bitch in
                classes[i].waitlistStudent(netid, priority);
                cout << "Student '" << netid << "' waitlisted for " << className << endl;
            }
        }
    }
    if (!found) cout << "**Invalid class name, try again..." << endl;

    cout << endl;
}

void processCommand(ClassReg classes[], istream & input)
{
    string file;
    ifstream infile;
    input >> file;

    infile.open(file);
    if (!infile.good())
    {
        cout << "**Unable to open '" << file << "'" << endl;
        return;
    }
    cout << "**Processing commands from '" << file << "'" << endl;

    processPrompt(infile, false, classes);

    cout << "**Done processing '" << file << "'" << endl;
    cout << endl;
}

void outputCommand(ClassReg classes[], istream & input)
{
    string file;
    ofstream outfile;
    input >> file;

    cout << "Enrollment data output to '" << file << "'" << endl;
    cout << endl;

    outfile.open(file);

    for (int i = 0; i < 5; i++)
    {
        // name
        outfile << classes[i].getName() << endl;
        // capacity
        outfile << classes[i].getCapacity() << endl;
        // enrolled students
        for (int j = 0; j < classes[i].numEnrolled(); j++)
        {
            outfile << classes[i].retrieveEnrolledStudent(j) << " ";
        }
        outfile << "#" << endl;

        // waitlisted students
        for (int j = 0; j < classes[i].numWaitlisted(); j++)
        {
            string netid;
            int priority;
            
            classes[i].retrieveWaitlistedStudent(j, netid, priority);

            outfile << netid << " " << priority << " ";
        }
        outfile << "#" << endl;
    }

    outfile.close();
}

void execute(ClassReg classes[], string command, istream & input)
{
    if (command == "help" || command == "h") helpCommand();
    else if (command == "stats" || command == "s") statsCommand(classes);
    else if (command == "list" || command == "l") listCommand(classes, input);
    else if (command == "increase" || command == "i") increaseCommand(classes, input);
    else if (command == "enroll" || command == "e") enrollCommand(classes, input);
    else if (command == "waitlist" || command == "w") waitlistCommand(classes, input);
    else if (command == "process" || command == "p") processCommand(classes, input);
    else if (command == "output" || command == "o") outputCommand(classes, input);
    else
    {
        cout << "**Invalid command, please try again..." << endl;
    }
}

void processPrompt(istream & input, bool keyboard, ClassReg classes[])
{
    string cmd;

    if (keyboard) 
        cout << "Enter a command (help for more info, quit to stop)>" << endl;
    
    input >> cmd;

    while (cmd != "quit" && cmd != "q")
    {
        execute(classes, cmd, input);
        if (keyboard) 
            cout << "Enter a command (help for more info, quit to stop)>" << endl;
        
        input >> cmd;
    }
}

void sort(string students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        int minIndex = i;
      
        for (int j = i + 1; j < numStudents; j++) {
            if (students[j] < students[minIndex]) {
                minIndex = j;
            }
        }
      
        string temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
}  

int main() 
{
    cout << "**CS Enrollment System**" << endl;

    string infilename = "enrollments.txt";
    ifstream infile;
    ClassReg classes[5]; 

    cout << "Enter enrollments filename>" << endl;
    cin >> infilename;
    cout << endl;
    
    infile.open(infilename);
    if (!infile.good())
    {
        cout << "** Error: unable to open enrollments file '" << infilename << "'" << endl;
        return 0;
    }

    // retrieve all the data from `enrollments.txt`
    for (int i = 0; i < 5; i++)
    {
        // name and capacity
        string name;
        int capacity;
        infile >> name >> capacity;

        classes[i].setName(name);
        classes[i].setCapacity(capacity);

        string enetid;
        infile >> enetid;

        // enrolled
        while (enetid != "#")
        {
            classes[i].enrollStudent(enetid);

            infile >> enetid;
        }

        // waitlisted 
        string wnetid;
        infile >> wnetid;

        while (wnetid != "#")
        {
            int priority;
            infile >> priority;

            classes[i].waitlistStudent(wnetid, priority);

            infile >> wnetid;
        }
    }

    processPrompt(cin, true, classes);

    infile.close();

    cout << "**Done**" << endl;
 
    return 0;
}
