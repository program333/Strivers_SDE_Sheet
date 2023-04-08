https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/


// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include <bits/stdc++.h>
using namespace std;

/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
int search(int mat[4][4], int n, int x)
{
	if (n == 0)
		return -1;

	int smallest = mat[0][0], largest = mat[n - 1][n - 1];
	if (x < smallest || x > largest)
		return -1;

	// set indexes for top right element
	int i = 0, j = n - 1;
	while (i < n && j >= 0) {
		if (mat[i][j] == x) {
			cout << "Element found at " << i << ", " << j;
			return 1;
		}
		if (mat[i][j] > x)
			j--;

		// Check if mat[i][j] < x
		else
			i++;
	}

	cout << "n Element not found";
	return 0;
}

// Driver code
int main()
{
	int mat[4][4] = { { 10, 20, 30, 40 },
					{ 15, 25, 35, 45 },
					{ 27, 29, 37, 48 },
					{ 32, 33, 39, 50 } };

	// Function call
	search(mat, 4, 29);

	return 0;
}

/*
Output
Element found at 2, 1
Time Complexity: O(N), Only one traversal is needed, i.e, i from 0 to n and j from n-1 to 0 with at most 2*N steps. 
The above approach will also work for the M x N matrix (not only for N x N). Complexity would be O(M + N)
Auxiliary Space: O(1), No extra space is required
*/
