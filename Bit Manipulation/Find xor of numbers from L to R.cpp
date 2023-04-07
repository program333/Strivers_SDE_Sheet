https://www.geeksforgeeks.org/find-xor-of-numbers-from-the-range-l-r/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the XOR of elements
// from the range [l, r]
int findXOR(int l, int r)
{
	int ans = 0;
	for (int i = l; i <= r; i++) {
		ans = ans ^ i;
	}
	return ans;
}

// Driver code
int main()
{
	int l = 4, r = 8;

	cout << findXOR(l, r);

	return 0;
}

/*
Output
8
Time complexity: O(N)
Auxiliary Space: O(1)
*/
