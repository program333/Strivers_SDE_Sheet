https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	   int low = 0, high = n-1;

       if(arr[low] <= arr[high]) return 0;
       
       while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] > arr[mid+1]){
                return mid+1;
            }
            else if(arr[mid] < arr[mid-1]){
                return mid;
            }
            else if(arr[low]<=arr[mid]){
                low = mid+1;
            }
            else if(arr[mid]<=arr[high]){
                high = mid-1;
            }
       }
        return 0;
	}

};

// Binary Search based C++ program to find number
// of rotations in a sorted and rotated array.
#include <bits/stdc++.h>
using namespace std;

// Returns count of rotations for an array which
// is first sorted in ascending order, then rotated
int countRotations(int arr[], int low, int high)
{
	// This condition is needed to handle the case
	// when the array is not rotated at all
	if (high < low)
		return 0;

	// If there is only one element left
	if (high == low)
		return low;

	// Find mid
	int mid = low + (high - low) / 2; /*(low + high)/2;*/

	// Check if element (mid+1) is minimum element.
	// Consider the cases like {3, 4, 5, 1, 2}
	if (mid < high && arr[mid + 1] < arr[mid])
		return (mid + 1);

	// Check if mid itself is minimum element
	if (mid > low && arr[mid] < arr[mid - 1])
		return mid;

	// Decide whether we need to go to left half or
	// right half
	if (arr[high] > arr[mid])
		return countRotations(arr, low, mid - 1);

	return countRotations(arr, mid + 1, high);
}

// Driver code
int main()
{
	int arr[] = { 15, 18, 2, 3, 6, 12 };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << countRotations(arr, 0, N - 1);
	return 0;
}


/*
Output
2
Time Complexity: O(log N) 
Auxiliary Space: O(log N)  [this is the space of recursion stack]
*/
