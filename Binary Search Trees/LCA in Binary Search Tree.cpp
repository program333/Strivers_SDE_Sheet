https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/


// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *left, *right;
};

/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node* lca(node* root, int n1, int n2)
{
	if (root == NULL)
		return NULL;

	// If both n1 and n2 are smaller
	// than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than
	// root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}

/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

/* Driver code*/
int main()
{
	// Let us construct the BST
	// shown in the above figure
	node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	// Function calls
	int n1 = 10, n2 = 14;
	node* t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;
	return 0;
}

/*
LCA of 10 and 14 is 12 
LCA of 14 and 8 is 8 
LCA of 10 and 22 is 20 
Time Complexity: O(H). where H is the height of the tree.
Auxiliary Space: O(H), If recursive stack space is ignored, the space complexity of the above solution is constant.
*/
