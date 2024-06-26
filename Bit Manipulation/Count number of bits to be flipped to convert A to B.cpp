https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/


// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function that count set bits
int countSetBits(int Xor)
{
        int count=0;
        while(Xor){
           if(Xor & 1){
               count++;
           }
           Xor=Xor>>1;
        }
        
        return count;
}

// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
	// Return count of set bits in
	// a XOR b
	return countSetBits(a ^ b);
}

// Driver code
int main()
{
	int a = 10;
	int b = 20;

	// Function call
	cout << FlippedCount(a, b) << endl;
	return 0;
}

/*
Output
4
Time Complexity: O(K) where K is the number of bits
Auxiliary Space: O(1)

Note: Set bits in (a XOR b) can also be computer using built in function __builtin_popcount() in C/C++
*/
