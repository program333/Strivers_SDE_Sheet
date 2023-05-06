https://www.geeksforgeeks.org/set-rightmost-unset-bit/

// C++ implementation to set the rightmost unset bit
#include <bits/stdc++.h>
using namespace std;

// function to find the position
// of rightmost set bit
int getPosOfRightmostSetBit(int n)
{
	return log2(n&-n)+1;
}

int setRightmostUnsetBit(int n)
{
	// if n = 0, return 1
	if (n == 0)
		return 1;
	
	// if all bits of 'n' are set
	if ((n & (n + 1)) == 0)
		return n;
	
	// position of rightmost unset bit in 'n'
	// passing ~n as argument
	int pos = getPosOfRightmostSetBit(~n);
	
	// set the bit at position 'pos'
	return ((1 << (pos - 1)) | n);
}

// Driver program to test above
int main()
{
	int n = 21;
	cout << setRightmostUnsetBit(n);
	return 0;
}
