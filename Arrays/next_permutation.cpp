https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

/*
Input format: Arr[] = {1,3,2}

Output: Arr[] = {2,1,3}

Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the next permutation
void nextPermutation(vector<int>& arr)
{
	next_permutation(arr.begin(),arr.end());
}

// Driver code
int main()
{

	// Given input array
	vector<int> arr = { 1, 2, 3, 6, 5, 4 };

	// Function call
	nextPermutation(arr);

	// Printing the answer
	for (auto i : arr) {
		cout << i << " ";
	}

	return 0;
}



/*
Follow the steps below to implement the above observation:

Iterate over the given array from end and find the first index (pivot) which doesn’t follow property of non-increasing suffix, (i.e,  arr[i] < arr[i + 1]).
Check if pivot index does not exist 
This means that the given sequence in the array is the largest as possible. So, swap the complete array.
Otherwise, Iterate the array from the end and find for the successor of pivot in suffix.
Swap the pivot and successor
Minimize the suffix part by reversing the array from pivot + 1 till N.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to find the next permutation
void nextPermutation(vector<int>& arr)
{
	int n = arr.size(), i, j;

	// Find for the pivot element.
	// A pivot is the first element from
	// end of sequenc ewhich doesn't follow
	// property of non-increasing suffix
	for (i = n - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) {
			break;
		}
	}

	// Check if pivot is not found
	if (i < 0) {
		reverse(arr.begin(), arr.end());
	}

	// if pivot is found
	else {

		// Find for the successor of pivot in suffix
		for (j = n - 1; j > i; j--) {
			if (arr[j] > arr[i]) {
				break;
			}
		}

		// Swap the pivot and successor
		swap(arr[i], arr[j]);

		// Minimise the suffix part
		reverse(arr.begin() + i + 1, arr.end());
	}
}

// Driver code
int main()
{

	// Given input array
	vector<int> arr = { 1, 2, 3, 6, 5, 4 };

	// Function call
	nextPermutation(arr);

	// Printing the answer
	for (auto i : arr) {
		cout << i << " ";
	}

	return 0;
}

/*
Time Complexity: O(N), where N is the size of the given array.
Auxiliary Space: O(1)


*/
