https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

// A recursive solution for subset sum problem
#include <iostream>
using namespace std;

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{

	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0)
		return false;

	// If last element is greater than sum,
	// then ignore it
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);

	/* else, check if sum can be obtained by any
of the following:
	(a) including the last element
	(b) excluding the last element */
	return isSubsetSum(set, n - 1, sum)
		|| isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Driver code
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout <<"Found a subset with given sum";
	else
		cout <<"No subset with given sum";
	return 0;
}



// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Taking the matrix as globally
int tab[2000][2000];

// Check if possible subset with
// given sum is possible or not
int subsetSum(int a[], int n, int sum)
{
	
	// If the sum is zero it means
	// we got our expected sum
	if (sum == 0)
		return 1;
		
	if (n <= 0)
		return 0;

	// If the value is not -1 it means it
	// already call the function
	// with the same value.
	// it will save our from the repetition.
	if (tab[n - 1][sum] != -1)
		return tab[n - 1][sum];

	// if the value of a[n-1] is
	// greater than the sum.
	// we call for the next value
	if (a[n - 1] > sum)
		return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
	else
	{
		
		// Here we do two calls because we
		// don't know which value is
		// full-fill our criteria
		// that's why we doing two calls
		return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
					subsetSum(a, n - 1, sum - a[n - 1]);
	}
}

// Driver Code
int main()
{
	// Storing the value -1 to the matrix
	memset(tab, -1, sizeof(tab));
	int n = 5;
	int a[] = {1, 5, 3, 7, 4};
	int sum = 12;

	if (subsetSum(a, n, sum))
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;


}

/*
Output
YES
Complexity Analysis: 

Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n) + O(n) -> O(sum*n) = the size of 2-D array is sum*n and O(n)=auxiliary stack space.
*/
