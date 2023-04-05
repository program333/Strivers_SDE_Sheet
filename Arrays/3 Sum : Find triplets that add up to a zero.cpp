https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/
https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/




#include<bits/stdc++.h>

using namespace std;
vector < vector < int >> threeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}

int main() {
  vector < int > arr { -1, 0, 1, 2, -1, -4};
  vector < vector < int >> ans;
  ans = threeSum(arr);
  cout << "The triplets are as follows: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

/*
Output:

The triplets are as follows:
-1 0 1
-1 2 -1
0 1 -1

Time Complexity : O(n^3)   // 3 loops

Space Complexity : O(3*k)  // k is the no.of triplets
*/


// C++ program to find a triplet
#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
	int l, r;
	/* Sort the elements */
	sort(A, A + arr_size);
	/* Now fix the first element one by one and find the
	other two elements */
	for (int i = 0; i < arr_size - 2; i++) {

		// To find the other two elements, start two index
		// variables from two corners of the array and move
		// them toward each other
		l = i + 1; // index of the first element in the
		// remaining elements
		r = arr_size - 1; // index of the last element
		while (l < r) {
			if (A[i] + A[l] + A[r] == sum) {
				printf("Triplet is %d, %d, %d", A[i], A[l],A[r]);
				return true;
			}
			else if (A[i] + A[l] + A[r] < sum)
				l++;
			else // A[i] + A[l] + A[r] > sum
				r--;
		}
	}
	// If we reach here, then no triplet was found
	return false;
}

/* Driver program to test above function */
int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);
	find3Numbers(A, arr_size, sum);
	return 0;
}

/*
Triplet is 4, 8, 10
Complexity Analysis: 
Time complexity: O(N^2). 
There are only two nested loops traversing the array, so time complexity is O(n^2). 
Two pointers algorithm takes O(n) time and the first element can be fixed using another nested traversal.
Space Complexity: O(1). 
As no extra space is required.
*/
