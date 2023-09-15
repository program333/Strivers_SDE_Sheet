
https://www.geeksforgeeks.org/next-smaller-element/

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<int> help_classmate(vector<int> arr, int n){
        // Your code here
        stack<int> s;
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            while(!s.empty()&&s.top()>=arr[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
            s.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Simple C++ program to print
// next smaller elements in a given array
#include "bits/stdc++.h"
using namespace std;

/* prints element and NSE pair
for all elements of arr[] of size n */
void printNSE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++)
	{
		next = -1;
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << " -- "
			<< next << endl;
	}
}

// Driver Code
int main()
{
	int arr[]= {11, 13, 21, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}


// A Stack based C++ program to find next
// smaller element for all array elements
#include <bits/stdc++.h>
using namespace std;

// prints NSE for elements of array arr[] of size n

void printNSE(int arr[], int n)
{
	stack<pair<int, int> > s;
	vector<int> ans(n);

	// iterate for rest of the elements
	for (int i = 0; i < n; i++) {
		int next = arr[i];

		// if stack is empty then this element can't be NSE
		// for any other element, so just push it to stack
		// so that we can find NSE for it, and continue
		if (s.empty()) {
			s.push({ next, i });
			continue;
		}

		// while stack is not empty and the top element is
		// greater than next
		// a) NSE for top is next, use top's index to
		// maintain original order
		// b) pop the top element from stack

		while (!s.empty() && s.top().first > next) {
			ans[s.top().second] = next;
			s.pop();
		}

		// push next to stack so that we can find NSE for it

		s.push({ next, i });
	}

	// After iterating over the loop, the remaining elements
	// in stack do not have any NSE, so set -1 for them

	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ---> " << ans[i] << endl;
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}

/*
Time Complexity: O(N)    

As we use only single for loop and all the elements in the stack are push and popped atmost once.

Auxiliary Space: O(N)

As extra space is used for storing the elements of the stack. 
*/
