https://www.geeksforgeeks.org/find-the-next-greater-element-in-a-circular-array/

// C++ program to demonstrate the use of circular
// array without using extra memory space
#include <bits/stdc++.h>
using namespace std;

// Function to find the Next Greater Element(NGE)
void printNGE(int A[], int n)
{
	int k;
	for(int i = 0; i < n; i++)
	{
		// Initialise k as -1 which is printed
		// when no NGE found
		k = -1;
		for(int j = i + 1; j < n + i; j++)
		{
			if (A[i] < A[j % n])
			{
				cout <<" "<< A[j % n];
				k = 1;
				break;
			}
		}
		// Gets executed when no NGE found
		if (k == -1)
			cout << "-1 ";
	}
}

// Driver Code
int main()
{
	// Given array arr[]
	int arr[] = { 8, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);
	// Function call
	printNGE(arr, N);
	return 0;
}
/*
Output
-1  7 8
 Time Complexity: O(n2) 
Auxiliary Space: O(1)
*/



#include <bits/stdc++.h>
using namespace std;

// Function to find the Next Greater Element(NGE)
void printNGE(int a[], int n)
{
	stack<int> s;
	vector<int> ans(n);
	for (int i = 2 * n - 1; i >= 0; i--) {
		while (!s.empty() && a[i % n] >= s.top())
			s.pop();
		if (i < n) {
			if (!s.empty())
				ans[i] = s.top();
			else
				ans[i] = -1;
		}
		s.push(a[i % n]);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 8, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, N);
	return 0;
}

/*
Output
-1 7 8 
Time Complexity: O(N)
Auxiliary Space: O(N)
*/
