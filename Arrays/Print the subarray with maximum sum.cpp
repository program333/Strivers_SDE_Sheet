https://www.geeksforgeeks.org/print-the-maximum-subarray-sum/

/*
Efficient Approach: The idea is to use the Kadane’s Algorithm to find the maximum subarray sum and store the starting and ending index of the
subarray having maximum sum and print the subarray from starting index to ending index. Below are the steps:

Initialize 3 variables endIndex to 0, currMax, and globalMax to first value of the input array.
For each element in the array starting from index(say i) 1, update currMax to max(nums[i], nums[i] + currMax) and globalMax and endIndex to i only if currMax > globalMax.
To find the start index, iterate from endIndex in the left direction and keep decrementing the value of globalMax until it becomes 0. The point at which it becomes 0 is the start index.
Now print the subarray between [start, end].
*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to print the elements
// of Subarray with maximum sum
void SubarrayWithMaxSum(vector<int>& nums)
{
	// Initialize currMax and globalMax
	// with first value of nums
	int endIndex, currMax = nums[0];
	int globalMax = nums[0];

	// Iterate for all the elements
	// of the array
	for (int i = 1; i < nums.size(); ++i) {

		// Update currMax
		currMax = max(nums[i],
					nums[i] + currMax);

		// Check if currMax is greater
		// than globalMax
		if (currMax > globalMax) {
			globalMax = currMax;
			endIndex = i;
		}
	}

	int startIndex = endIndex;

	// Traverse in left direction to
	// find start Index of subarray
	while (startIndex >= 0) {

		globalMax -= nums[startIndex];

		if (globalMax == 0)
			break;

		// Decrement the start index
		startIndex--;
	}

	// Printing the elements of
	// subarray with max sum
	for (int i = startIndex;
		i <= endIndex; ++i) {

		cout << nums[i] << " ";
	}
}

// Driver Code
int main()
{
	// Given array arr[]
	vector<int> arr
		= { -2, -5, 6, -2,
			-3, 1, 5, -6 };

	// Function call
	SubarrayWithMaxSum(arr);
	return 0;
}

/*
Output
6 -2 -3 1 5 
Time complexity: O(N) 
Auxiliary Space: O(1)
*/
