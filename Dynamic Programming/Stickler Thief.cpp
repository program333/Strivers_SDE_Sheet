https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum

int rec(vector<int>& nums, int idx, vector<int>& dp)
{
	if (idx >= nums.size())
		return 0;
	if (dp[idx] != -1)
		return dp[idx];
	return dp[idx]
		= max(rec(nums, idx + 1, dp),
				nums[idx] + rec(nums, idx + 2, dp));
}
int findMaxSum(vector<int>& nums, int N)
{
	vector<int> dp(N + 1, -1);
	return rec(nums, 0, dp);
}

// Driver Code
int main()
{
	// Creating the array
	vector<int> arr = { 5, 5, 10, 100, 10, 5 };
	int N = arr.size();

	// Function call
	cout << findMaxSum(arr, N) << endl;
	return 0;
}

/*
Output
110
Time complexity: O(N) (recursion)


Space complexity: O(N)+O(N), one is recursive stack space and another O(N) is for dp array.
*/
