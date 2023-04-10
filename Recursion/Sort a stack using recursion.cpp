https://www.geeksforgeeks.org/sort-a-stack-using-recursion/

#include <stack>
#include <iostream>

using namespace std;

// Function to sort a stack using recursion
void sortStack(stack<int> &s) {
	// If the stack is empty, return
	if (s.empty())
		return;
	
	// Remove the top element of the stack
	int x = s.top();
	s.pop();
	
	// Sort the remaining elements in the stack using recursion
	sortStack(s);
	
	// Create two auxiliary stacks
	stack<int> tempStack;
	
	// Move all elements that are greater than x from the main stack to the tempStack
	while (!s.empty() && s.top() > x) {
		tempStack.push(s.top());
		s.pop();
	}
	
	// Push x back into the main stack
	s.push(x);
	
	// Move all elements from tempStack back to the main stack
	while (!tempStack.empty()) {
		s.push(tempStack.top());
		tempStack.pop();
	}
}

int main() {
	// Create a stack
	stack<int> s;
	
	// Push elements into the stack
	s.push(34);
	s.push(3);
	s.push(31);
	s.push(98);
	s.push(92);
	s.push(23);
	
	// Sort the stack
	sortStack(s);
	
	// Print the sorted elements
	cout << "Sorted numbers are: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}


/*
Output
Sorted numbers are: 98 92 34 31 23 3 
Time complexity: O(n^2)

Auxiliary Space: O(n)
*/
