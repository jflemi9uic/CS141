//
// Program to simulate coin flips and report % of heads and tails.
//
// Author: ???
// Originally by: Prof. Hummel, U. of Illinois Chicago, Spring 2021
//

#include <iostream>
#include <random>

using namespace std;


//
// flipNcoins
//
// Given an array A with N locations, fills the array with 0's and 
// 1's where 0 denotes "heads" and 1 denotes "tails".  The numbers
// are generated randomly.  Pass a non-zero value for mode to get
// different values each time you call; pass 0 to get the same
// values each time you call --- this is helpful for testing.
//
void flipNcoins(int A[], int N, int mode)
{
   random_device  rd;
   mt19937        gen1(rd());  // random seed => gen different sequence each time
   mt19937        gen2(123);   // same seed => gen same sequence every time
   uniform_real_distribution<double> next(0.0, 1.0);  // random in [0.0-1.0)

	double coin;
	int    i = 0;
	
	//
	// flip N times:
	//
	while (i < N)
	{
		//
		// simulate flipping a coin by generating a random number in the
		// range 0..1:
		//
		if (mode == 0)  // same values every time:
		{
			coin = next(gen2);
		}
		else  // random values:
		{
			coin = next(gen1);
		}
		
		//
		// it's "heads" if in the range [0,0.5) and "tails" if in the 
		// range [0.5, 1.0):
		//
		if (coin < 0.5)  // let's call that heads
		{
			A[i] = 0;  // heads:
		}
		else
		{
			A[i] = 1;  // tails:
		}

		i++;
	} // i = N
   
   // 
   // flip an extra coin just for fun:
   //
// 	if (mode == 0)  // same values every time:
// 	{
// 		coin = next(gen2);
// 	}
// 	else  // random values:
// 	{
// 		coin = next(gen1);
// 	}
   
// 	if (coin < 0.5)  // let's call that heads
// 	{
// 		A[i] = 0;  // heads:
// 	}
// 	else
// 	{
// 		A[i] = 1;  // tails:
// 	} 
}


// 
// outputNcoins
//
// Given an array of N integers, outputs each value to the console
// followed by a space.  These all appear on one line, which gets
// wrapped if the line is long.  The values should be 0's and 1's, 
// denoting "heads" and "tails".
//

//
// TODO: define function here
//

void outputNcoins(int * arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// 
// outputFlipStats
//
// Given an array of N integers consisting of 0's and 1's (where 
// 0 denotes "heads" and 1 denotes "tails"), outputs the total #
// of heads and tails along with their percentages. The percentages
// should be computed as real numbers (double).
//
// Example output:
//    Heads: 5011 at 50.11%
//    Tails: 4989 at 49.89%
//

//
// TODO: define function here
//

void outputFlipStats(int * arr, int size) {
    double numHeads = 0.0;
    double numTails = 0.0;
    
    double headsPerc = 0.0;
    double tailsPerc = 0.0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            numHeads++;
        } else {
            numTails++;
        }
    }
    
    headsPerc = numHeads / size * 100;
    tailsPerc = numTails / size * 100;
    
    cout << "Heads: " << numHeads << " at " << headsPerc << "%" << endl;
    cout << "Tails: " << numTails << " at " << tailsPerc << "%" << endl;
}


//
// main:
//
int main()
{	
	int  mode;
	int  N;  // array size

	cout << "How many coins do you want to flip? ";
	cin >> N;
	
	cout << "Enter 0 for testing mode, 1 for random results: ";
	cin >> mode;

	//
	// dynamically allocate an array to hold the result
	// of each coin flip:
	//
	int* A;  // pointer to first element of the array
	
	A = new int[N];  // dynamically-allocate N elements
	
	//
	// flip N coins:
	//
	flipNcoins(A, N, mode);
	
	//
	// output the coins:
	//
	
	// TODO: call function
	outputNcoins(A, N);
	
	//
	// now output stats on heads vs. tails:
	//
	
	// TODO: call function
    outputFlipStats(A, N);

    delete[] A;
   
	//
	// done:
	//
	return 0;
}

