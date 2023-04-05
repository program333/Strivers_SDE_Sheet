https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
int main()
{
int arr[] = {10, 2, -2, -20, 10};
int k = -10;
int n = sizeof(arr) / sizeof(arr[0]);
int res = 0;

// Calculate all subarrays
for (int i = 0; i < n; i++)
{
	int sum = 0;
	for (int j = i; j < n; j++)
	{
	// Calculate required sum
	sum += arr[j];
	// Check if sum is equal to required sum
	if (sum == k)
		res++;
	}
}
cout << (res) << endl;
}

/*
Output
3
Time Complexity : O(n2)
Auxiliary Space: O(1)
*/


// C++ program to find number of subarrays with sum exactly
// equal to k.
#include <bits/stdc++.h>
using namespace std;

// Function to find number of subarrays with sum exactly
// equal to k.
int findSubarraySum(int arr[], int n, int sum)
{
	// STL map to store number of subarrays starting from
	// index zero having particular value of sum.
	unordered_map<int, int> prevSum;

	int res = 0;

	// Sum of elements so far.
	int currSum = 0;

	for (int i = 0; i < n; i++) {

		// Add current element to sum so far.
		currSum += arr[i];

		// If currsum is equal to desired sum, then a new
		// subarray is found. So increase count of
		// subarrays.
		if (currSum == sum)
			res++;

		// currsum exceeds given sum by currsum - sum. Find
		// number of subarrays having this sum and exclude
		// those subarrays from currsum by increasing count
		// by same amount.
		if (prevSum.find(currSum - sum) != prevSum.end())
			res += (prevSum[currSum - sum]);

		// Add currsum value to count of different values of
		// sum.
		prevSum[currSum]++;
	}

	return res;
}

int main()
{
	int arr[] = { 10, 2, -2, -20, 10 };
	int sum = -10;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findSubarraySum(arr, n, sum);
	return 0;
}

/*
Output
3
Time Complexity: O(n) 
Auxiliary Space: O(n)
*/

