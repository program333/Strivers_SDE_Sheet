

/*
Solution 1: Brute force

Approach: For each index, we have to find the amount of water that can be stored and we have to sum it up.
If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the
elevation at that index.
*/
#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
/*
Output: The water that can be trapped is 6

Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.

Space Complexity: O(1).

*/

/*
Solution 2:Better solution

Intuition: We are taking O(N) for computing leftMax and rightMax at each index. 
The complexity can be boiled down to O(1) if we precompute the leftMax and rightMax at each index.

Approach: Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand.
Then use the formula min(prefix[I], suffix[i])-arr[i] to compute water trapped at each index.
*/

#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
/*
Output: The water that can be trapped is 6

Time Complexity: O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.

Space Complexity: O(N)+O(N) for prefix and suffix arrays.
*/
