// 
// Author: James Fleming UIC Spring 2021
// Project 01 part 01
// 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    cout << "** Welcome to UIC Bank v1.0 ** " << endl;

    cout << fixed;
    cout << setprecision(2);

    string infilename;
    ifstream infile;

    cout << "Enter bank filename>" << endl;
    cin >> infilename;

    cout << "** Inputting account data..." << endl;

    infile.open(infilename);
    if (!infile.good()) {
        cout << "**Error: unable to open input file '" << infilename << "'" << endl;;
        return 0;
    }

    int acct1, acct2, acct3, acct4, acct5;
    double bal1, bal2, bal3, bal4, bal5;

    infile >> acct1 >> bal1;
    infile >> acct2 >> bal2;
    infile >> acct3 >> bal3;
    infile >> acct4 >> bal4;
    infile >> acct5 >> bal5;

    // display all accounts
    cout << "** Outputting account data..." << endl;
    cout << "Account " << acct1 << ": balance $" << bal1 << endl;
    cout << "Account " << acct2 << ": balance $" << bal2 << endl;
    cout << "Account " << acct3 << ": balance $" << bal3 << endl;
    cout << "Account " << acct4 << ": balance $" << bal4 << endl;
    cout << "Account " << acct5 << ": balance $" << bal5 << endl;

    int flag = 1;
    cout << "** Processing user commands..." << endl;

    while (flag == 1) {
        cout << "Enter command (+, -, ?, ^, *, x):" << endl;
        string command;
        cin >> command;

        // deposit
        if (command == "+") {
            int account;
            double balance;
            cin >> account;
            cin >> balance;

            if (account == acct1) {
                bal1 += balance;
                cout << "Account " << acct1 << ": balance $" << bal1 << endl;
            } else if (account == acct2) {
                bal2 += balance;
                cout << "Account " << acct2 << ": balance $" << bal2 << endl;
            } else if (account == acct3) {
                bal3 += balance;
                cout << "Account " << acct3 << ": balance $" << bal3 << endl;
            } else if (account == acct4) {
                bal4 += balance;
                cout << "Account " << acct4 << ": balance $" << bal4 << endl;
            } else if (account == acct5) {
                bal5 += balance;
                cout << "Account " << acct5 << ": balance $" << bal5 << endl;
            } else {
                cout << "** Invalid account, transaction ignored" << endl;
            }
            ofstream outfile;
            outfile.open(infilename);
            outfile << acct1 << " " << bal1 << endl;
            outfile << acct2 << " " << bal2 << endl;
            outfile << acct3 << " " << bal3 << endl;
            outfile << acct4 << " " << bal4 << endl;
            outfile << acct5 << " " << bal5 << endl;
            outfile.close();
        // withdrawl
        } else if (command == "-") {
            int account;
            double balance;
            cin >> account;
            cin >> balance;

            if (account == acct1) {
                bal1 -= balance;
                cout << "Account " << acct1 << ": balance $" << bal1 << endl;
            } else if (account == acct2) {
                bal2 -= balance;
                cout << "Account " << acct2 << ": balance $" << bal2 << endl;
            } else if (account == acct3) {
                bal3 -= balance;
                cout << "Account " << acct3 << ": balance $" << bal3 << endl;
            } else if (account == acct4) {
                bal4 -= balance;
                cout << "Account " << acct4 << ": balance $" << bal4 << endl;
            } else if (account == acct5) {
                bal5 -= balance;
                cout << "Account " << acct5 << ": balance $" << bal5 << endl;
            } else {
                cout << "** Invalid account, transaction ignored" << endl;
            }

            ofstream outfile;
            outfile.open(infilename);
            outfile << acct1 << " " << bal1 << endl;
            outfile << acct2 << " " << bal2 << endl;
            outfile << acct3 << " " << bal3 << endl;
            outfile << acct4 << " " << bal4 << endl;
            outfile << acct5 << " " << bal5 << endl;
            outfile.close();
        // check balance
        } else if (command == "?") {
            int account;
            cin >> account;
            if (account == acct1) {
                cout << "Account " << acct1 << ": balance $" << bal1 << endl;
            } else if (account == acct2) {
                cout << "Account " << acct2 << ": balance $" << bal2 << endl;
            } else if (account == acct3) {
                cout << "Account " << acct3 << ": balance $" << bal3 << endl;
            } else if (account == acct4) {
                cout << "Account " << acct4 << ": balance $" << bal4 << endl;
            } else if (account == acct5) {
                cout << "Account " << acct5 << ": balance $" << bal5 << endl;
            } else {
                cout << "** Invalid account, transaction ignored" << endl;
            }
        // see highest account
        } else if (command == "^") {
            double largest = bal1;
            largest = largest > bal2 ? largest : bal2;
            largest = largest > bal3 ? largest : bal3;
            largest = largest > bal4 ? largest : bal4;
            largest = largest > bal5 ? largest : bal5;

            if (largest == bal1) {
                cout << "Account " << acct1 << ": balance $" << bal1 << endl;
            } else if (largest == bal2) {
                cout << "Account " << acct2 << ": balance $" << bal2 << endl;
            } else if (largest == bal3) {
                cout << "Account " << acct3 << ": balance $" << bal3 << endl;
            } else if (largest == bal4) {
                cout << "Account " << acct4 << ": balance $" << bal4 << endl;
            } else if (largest == bal5) {
                cout << "Account " << acct5 << ": balance $" << bal5 << endl;
            }
        // list all accounts
        } else if (command == "*") {
            cout << "Account " << acct1 << ": balance $" << bal1 << endl;
            cout << "Account " << acct2 << ": balance $" << bal2 << endl;
            cout << "Account " << acct3 << ": balance $" << bal3 << endl;
            cout << "Account " << acct4 << ": balance $" << bal4 << endl;
            cout << "Account " << acct5 << ": balance $" << bal5 << endl;
        // exit
        } else if (command == "x") {   
            flag = 0;
        } else {
            cout << "** Invalid command, try again..." << endl;
        }
    }
    
    /*
    not sure if this is needed for part two of the project??

    // +1 dollar
    infile.close();
    cout << "** Adding $1 to each balance..." << endl;
    bal1 += 1.0;
    bal2 += 1.0;
    bal3 += 1.0;
    bal4 += 1.0;
    bal5 += 1.0;

    string outfilename = infilename;
    ofstream outfile;

    outfile.open(outfilename);
    if (!outfile.good()){
        cout << "**Error: unable to open output file '" << outfilename << "'" << endl;
        return 0;
    }

    outfile << acct1 << " " << bal1 << endl;
    outfile << acct2 << " " << bal2 << endl;
    outfile << acct3 << " " << bal3 << endl;
    outfile << acct4 << " " << bal4 << endl;
    outfile << acct5 << " " << bal5 << endl;

    outfile.close();
    */

    cout << "** Saving account data..." << endl;
    cout << "** Done ** " << endl;

    return 0;
}