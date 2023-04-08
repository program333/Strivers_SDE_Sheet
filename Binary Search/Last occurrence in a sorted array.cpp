https://takeuforward.org/data-structure/last-occurrence-in-a-sorted-array/
https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/


#include<bits/stdc++.h>

using namespace std;

int solve(int n, int key, vector < int > & v) {
  int start = 0;
  int end = n - 1;
  int res = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      res = mid;
      start = mid + 1;

    } else if (key < v[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return res;
}

int main() {
  int n = 7;
  int key = 13;
  vector < int > v = {3,4,13,13,13,20,40};
  
  // returning the last occurrence index if the element is present otherwise -1
  cout << solve(n, key, v) << "\n";

  return 0;
}

/*
Output: 4

Time Complexity: O(log n)

Space Complexity: O(1)
