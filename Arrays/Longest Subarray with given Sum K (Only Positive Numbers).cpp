https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/
/*
Example 1:
Input:
arr = {7,1,6,0}, k = 7

Output: Length of the longest subarray with sum K is 3
Explanation:
 1 + 6 + 0 = 7, it is the longest subarray with sum 7 and length 3.
 */

#include<iostream>

#include<bits/stdc++.h>

using namespace std;

int longestSubArrWithSumK_BF(int arr[], int n, int k) {
  int maxLength = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (sum == k)
        maxLength = max(maxLength, (j - i + 1));
    }

  }
  return maxLength;
}

int main() {

  int arr[] = {7,1,6,0};
  int n = sizeof(arr) / sizeof(arr[0]), k = 7;

  cout << "Length of the longest subarray with sum K is " << 
  longestSubArrWithSumK_BF(arr, n, k);

  return 0;
}

/*
Output: Length of the longest subarray with sum K is 3

Time Complexity: O(n^2) time to generate all possible subarrays.

Space Complexity: O(1), we are not using any extra space
*/
