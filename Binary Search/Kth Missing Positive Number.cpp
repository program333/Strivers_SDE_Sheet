https://www.geeksforgeeks.org/k-th-missing-element-in-sorted-array/
https://leetcode.com/problems/kth-missing-positive-number/description/

// CPP program for above approach
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to find
// kth missing number
int missingK(vector<int>& arr, int k)
{
	int n = arr.size();
	int l = 0, u = n - 1, mid;

	while (l <= u) {
		mid = (l + u) / 2;

		int numbers_less_than_mid = arr[mid] - (mid + 1);

		// If the total missing number
		// count is equal to k we can iterate
		// backwards for the first missing number
		// and that will be the answer.
		if (numbers_less_than_mid == k) {

			// To further optimize we check
			// if the previous element's
			// missing number count is equal
			// to k. Eg: arr = [4,5,6,7,8]
			// If you observe in the example array,
			// the total count of missing numbers for all
			// the indices are same, and we are
			// aiming to narrow down the
			// search window and achieve O(logn)
			// time complexity which
			// otherwise would've been O(n).
			if (mid > 0 && (arr[mid - 1] - (mid)) == k) {
				u = mid - 1;
				continue;
			}
			// Else we return arr[mid] - 1.
			return arr[mid] - 1;
		}

		// Here we appropriately
		// narrow down the search window.
		if (numbers_less_than_mid < k) {
			l = mid + 1;
		}
		else if (k < numbers_less_than_mid) {
			u = mid - 1;
		}
	}

	// In case the upper limit is -ve
	// it means the missing number set
	// is 1,2,..,k and hence we directly return k.
	if (u < 0)
		return k;

	// Else we find the residual count
	// of numbers which we'd then add to
	// arr[u] and get the missing kth number.
	int less = arr[u] - (u + 1);
	k -= less;

	// Return arr[u] + k
	return arr[u] + k;
}

// Driver Code
int main()
{
	vector<int> arr = { 2, 3, 4, 7, 11 };
	int k = 5;

	// Function Call
	cout << "Missing kth number = " << missingK(arr, k)
		<< endl;
	return 0;
}

/*
Output
Missing kth number = 9
Time Complexity: O(logn), where n is the number of elements in the array.
Auxiliary Space: O(1)
*/
