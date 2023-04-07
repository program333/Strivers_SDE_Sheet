https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/

// C program to check if a given Binary Tree is symmetric
// or not
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A Binary Tree Node
typedef struct Node {
	int key;
	struct Node *left, *right;
} Node;

// Utility function to create new Node
Node* newNode(int key)
{
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// Returns true if trees with roots as root1 and root2 are
// mirror
bool isMirror(Node* root1, Node* root2)
{
	// If both trees are empty, then they are mirror images
	if (root1 == NULL && root2 == NULL)
		return true;

	// For two trees to be mirror images, the following
	// three conditions must be true
	// 1.) Their root node's key must be same
	// 2.) left subtree of left tree and right subtree of
	// right tree have to be mirror images
	// 3.) right subtree of left tree and left subtree of
	// right tree have to be mirror images
	if (root1 && root2 && root1->key == root2->key)
		return isMirror(root1->left, root2->right)
			&& isMirror(root1->right, root2->left);

	// if none of above conditions is true then root1
	// and root2 are not mirror images
	return false;
}

// Returns true if a tree is symmetric i.e. mirror image of
// itself
bool isSymmetric(Node* root)
{
	// Check if tree is mirror of itself
	return isMirror(root, root);
}

// Driver code
int main()
{
	// Let us construct the Tree shown in the above figure
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);

	if (isSymmetric(root))
		printf("Symmetric");
	else
		printf("Not symmetric");
	return 0;
}

/*
Output
Symmetric
Time Complexity: O(N)
Auxiliary Space: O(h) where h is the maximum height of the tree
*/
