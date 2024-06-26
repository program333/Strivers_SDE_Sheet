https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
https://takeuforward.org/data-structure/right-left-view-of-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        
        map<int,int>mp; // level, val
        queue<pair<TreeNode*, int>>Q; // node, level
        Q.push({root, 0});
        
        while(!Q.empty()){
            auto it = Q.front();
            Q.pop();
            TreeNode* node = it.first;
            int level = it.second;
            
            if(mp.find(level) == mp.end()) mp[level] = node->val;
            if(node->right != NULL) Q.push({node->right, level+1});
            if(node->left != NULL) Q.push({node->left, level+1});
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};


/*
Follow the steps below to solve the problem:

Perform Postorder traversal to get the rightmost node first
Maintain a variable name max_level which will store till which it prints the right view
While traversing the tree in a postorder manner if the current level is greater than max_level then print the current node and update max_level by the current level
*/
// C++ program to print right view of Binary Tree
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
// right view of a binary tree.
void rightViewUtil(struct Node* root, int level,
				int* max_level)
{
	// Base Case
	if (root == NULL)
		return;

	// If this is the last Node of its level
	if (*max_level < level) {
		cout << root->data << "\t";
		*max_level = level;
	}

	// Recur for right subtree first,
	// then left subtree
	rightViewUtil(root->right, level + 1, max_level);
	rightViewUtil(root->left, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(struct Node* root)
{
	int max_level = 0;
	rightViewUtil(root, 1, &max_level);
}

// Driver Code
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->right = newNode(8);

	rightView(root);

	return 0;
}

/*
Output
1    3    7    8    

Time Complexity: O(N), Traversing the Tree having N nodes
Auxiliary Space: O(N), Function Call stack space in the worst case.*/




class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
