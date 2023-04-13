https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-rotated-array-with-duplicates/

// C++ implementation of the above approach using iterative
// version of binary search
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int low, int high, int key)
{

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == key) {
			// if we have found our target element
			// return the index of target element
			return mid;
		}

		if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
			// It may happen in case of duplicates

			++low;
			--high;
			continue;
		}

		if (arr[low] <= arr[mid]) {
			// This means array is sorted from index low to
			// mid We will check that if target element lies
			// in left half or not

			if (key >= arr[low] && key < arr[mid])
				high = mid - 1;

			else
				// This means that our target lies in other
				// half of array So we shift low to mid+1 to
				// search in right half
				low = mid + 1;
		}

		else {
			// This means array is sorted between mid and
			// high index

			// This will check our target element is
			// in right half or not
			if (key <= arr[high] && key > arr[mid])
				low = mid + 1;

			else
				// Means our target is in left half
				high = mid - 1;
		}
	}

	// If target element is not present

	return -1;
}
// Driver Code
int main()
{
	int arr[] = { 3, 3, 1, 2, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int key = 3;
	cout << search(arr, 0, n - 1, key) << endl;

	return 0;
}


/*
Output
4
Time Complexity: O(N), where n represents the size of the given array. If all the elements are same, we may end up doing a linear search.
Auxiliary Space: O(1) 
*/
