https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k
https://www.geeksforgeeks.org/find-subarray-with-given-sum/
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





#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
