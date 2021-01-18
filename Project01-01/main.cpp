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

    cout << "** Saving account data..." << endl;
    cout << "** Done ** " << endl;

    return 0;
}