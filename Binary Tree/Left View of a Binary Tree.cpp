https://www.geeksforgeeks.org/print-left-view-binary-tree/
https://takeuforward.org/data-structure/right-left-view-of-binary-tree/


/*

Given the root of a binary tree, return the left view of its nodes' values. Assume the left and right child of a node makes a 45–degree angle with the parent.

Input:
		   1
		 /	 \
		/	  \
	   2	   3
	  		 /   \
	 	  	/	  \
		   5	   6
		 /   \
		/	  \
	   7	   8

Output: [1, 2, 5, 7]

Input:

	  1
	/   \
   /	 \
  2		  3
   \	 /
	\   /
	 4 5

Output: [1, 2, 4]

*/

class Solution
{
public:

	/*
		A binary tree node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/

	vector<int> findLeftView(Node* root)
	{
		// Write your code here...
		vector<int>ans;
		if(root == NULL) return ans;
		map<int,int>mp; // level, val
		queue<pair<Node*, int>>Q; // node, level
		Q.push({root, 0});
		
		while(!Q.empty()){
			Node* node = Q.front().first;
			int level = Q.front().second;
			Q.pop();
			
			if(mp.find(level) == mp.end()) mp[level] = node->data;
			if(node->left != NULL) Q.push({node->left, level+1});
			if(node->right != NULL) Q.push({node->right, level+1});
		}
		for(auto x:mp){
			ans.push_back(x.second);
		}
		return ans;
	}
};

// C++ program to print left view of Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

// A utility function to
// create a new Binary Tree Node
struct Node* newNode(int item)
{
	struct Node* temp
		= (struct Node*)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to print
// left view of a binary tree.
void leftViewUtil(struct Node* root, int level,
				int* max_level)
{
	// Base Case
	if (root == NULL)
		return;

	// If this is the first Node of its level
	if (*max_level < level) {
		cout << root->data << " ";
		*max_level = level;
	}

	// Recur for left subtree first,
	// then right subtree
	leftViewUtil(root->left, level + 1, max_level);
	leftViewUtil(root->right, level + 1, max_level);
}

// A wrapper over leftViewUtil()
void leftView(struct Node* root)
{
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

// Driver Code
int main()
{
	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	leftView(root);

	return 0;
}






class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
    }
    
    vector<int> leftSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
/*
Time Complexity: O(N)

Space Complexity: O(H)  
*/
