https://www.geeksforgeeks.org/count-number-of-nodes-in-a-complete-binary-tree/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of a Tree Node
class node {
public:
	int data;
	node* left;
	node* right;
};

// Function to get the count of nodes
// in complete binary tree
int totalNodes(node* root)
{
	if (root == NULL)
		return 0;

	int l = totalNodes(root->left);
	int r = totalNodes(root->right);

	return 1 + l + r;
}

// Helper function to allocate a new node
// with the given data
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return (Node);
}

// Driver Code
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(9);
	root->right->right = newNode(8);
	root->left->left->left = newNode(6);
	root->left->left->right = newNode(7);
	cout << totalNodes(root);
	return 0;
}

/*
Output
9
Time Complexity: O(N) as in traversal all the nodes are visited

Reason:

Recurrence Relation: T(N) = 2*T(N/2) + O(1) 
Solve via Master’s Theorem, you will get O(N) as Time.
Auxiliary Space: O(h) = O(log N)  as height of CBT is LogN
*/
