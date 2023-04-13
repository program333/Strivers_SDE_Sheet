https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
https://takeuforward.org/data-structure/minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr, int low, int high) {
	// If the array is not rotated
	if (arr[low] <= arr[high]) {
		return arr[low];
	}

	// Binary search
	while (low <= high) {
		int mid = (low + high) / 2;

		// Check if mid is the minimum element
		if (arr[mid] < arr[mid - 1]) {
			return arr[mid];
		}

		// If the right half is sorted, the minimum element must be in the left half
		if (arr[mid] > arr[high]) {
			low = mid + 1;
		}

		// If the left half is sorted, the minimum element must be in the right half
		else {
			high = mid - 1;
		}
	}

	// If no minimum element is found, return -1
	return -1;
}

// Driver program to test above functions
int main() {
	vector<int> arr = {5, 6, 1, 2, 3, 4};
	int N = arr.size();
	cout << "The minimum element is " << findMin(arr, 0, N - 1) << endl;
	return 0;
}


/*
Output
The minimum element is 1
Time complexity: O(log n) – where n is the number of elements in the array. This is because the algorithm uses binary search, which has a logarithmic time complexity.
Auxiliary Space: O(1) – the algorithm uses a constant amount of extra space to store variables such as low, high, and mid, regardless of the size of the input array.
*/
