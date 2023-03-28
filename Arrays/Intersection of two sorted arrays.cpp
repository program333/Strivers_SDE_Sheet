https://takeuforward.org/data-structure/intersection-of-two-sorted-arrays/

/*
Example 1:
Input: 
A: [1 2 3 3 4 5 6]
, B: [3 3 5]
Output: 3,3,5
Explanation: We are given two arrays A and B. 
The elements present in both the arrays  
are 3,3 and 5.
*/

#include<bits/stdc++.h>
using namespace std;

  vector<int> intersectionOfArrays(vector<int>A, vector<int>B){
    
  // Declare ans array.
  vector <int> ans;

  int i = 0, j = 0; 

  // to traverse the arrays
  while (i < A.size() && j < B.size()) {
      
    //if current element in i is smaller
    if (A[i] < B[j]) { 
      i++;
    } else if (B[j] < A[i]) {
      j++;
    } else {
        
      //both elements are equal
      ans.push_back(A[i]); 
      i++;
      j++;
    }
  }
  
  return ans;
    
}

int main() {
    
  // Array Initialisation.
  vector < int > A {1,2,3,3,4,5,6,7};
  vector < int > B {3,3,4,4,5,8};

  vector<int> ans = intersectionOfArrays(A,B);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

/*
Output:

3 3 4 5

Time Complexity: O(n) { Since the elements are compared within the single pass for both the arrays this approach would take a linear time and in 
the worst case O(n1+n2) where n1 = A.size() and n2 = B.size() }.

Space Complexity: O(1) { There is no extra space used in the two-pointers approach }.
*/


//Handling duplicate in Arrays 
https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/?ref=rp

// C++ program to find intersection of two sorted arrays
#include <bits/stdc++.h>
using namespace std;

/* Function prints Intersection of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
void print_intersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	set<int> s; //set for handling duplicate elements in intersection list
	while (i < m && j < n) {
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else /* if arr1[i] == arr2[j] */
		{
			s.insert(arr2[j]); //insertion in set s
			i++;
			j++;
		}
	}
	for(auto itr: s) //printing intersection set list
	{
		cout<<itr<<" ";
		}
		
}

/* Driver code */
int main()
{
	int arr1[] = { 1, 2, 2, 3, 4 };
	int arr2[] = { 2, 2, 4, 6, 7, 8 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// Function calling
	print_intersection(arr1, arr2, m, n);

	return 0;
}

/*
Output
2 4 
Time Complexity : O(m + n) 
Auxiliary Space : O(min(m, n))
*/
