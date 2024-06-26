https://takeuforward.org/data-structure/peak-element-in-array/
https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

#include<iostream>

using namespace std;

int peakEleOptimal(int arr[], int n) {
  int start = 0, end = n - 1;

  while (start < end) {
    int mid = (start + end) / 2;

    if (mid == 0)
      return arr[0] >= arr[1] ? arr[0] : arr[1];

    if (mid == n - 1)
      return arr[n - 1] >= arr[n - 2] ? arr[n - 1] : arr[n - 2];

    //Cheking whether peak ele is in mid position
    if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
      return arr[mid];

    //If left ele is greater then ignore 2nd half of the elements
    if (arr[mid] < arr[mid - 1])
      end = mid - 1;

    //Else ignore first half of the elements
    else
      start = mid + 1;
  }

  return arr[start];
}

int main() {

  int arr[] = {3, 5, 4, 1, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Peak Element is " << peakEleOptimal(arr, n);

  return 0;
}

/*
Output: Peak Element is 5

Time Complexity: O(log(n)), at every time we shrink the search space to half resulting in log(n) time complexity.

Space Complexity: O(1), we are not using any extra space.
*/
