https://www.geeksforgeeks.org/next-greater-element/
/*
Input: arr[] = [ 4 , 5 , 2 , 25 ]
Output:  4      –>   5
               5      –>   25
               2      –>   25
              25     –>   -1
Explanation: except 25 every element has an element greater than them present on the right side


*/

// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n)
{
	stack<int> s;

	/* push the first element to stack */
	s.push(arr[0]);

	// iterate for rest of the elements
	for (int i = 1; i < n; i++) {

		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}

		/* if stack is not empty, then
		pop an element from stack.
		If the popped element is smaller
		than next, then
		a) print the pair
		b) keep popping while elements are
		smaller and stack is not empty */
		while (s.empty() == false && s.top() < arr[i]) {
			cout << s.top() << " --> " << arr[i] << endl;
			s.pop();
		}

		/* push next to stack so that we can find
		next greater for it */
		s.push(arr[i]);
	}

	/* After iterating over the loop, the remaining
	elements in stack do not have the next greater
	element, so print -1 for them */
	while (s.empty() == false) {
		cout << s.top() << " --> " << -1 << endl;
		s.pop();
	}
}

/* Driver code */
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}

/*
Output
11 --> 13
13 --> 21
3 --> -1
21 --> -1
Time Complexity: O(N) 
Auxiliary Space: O(N)
*/
