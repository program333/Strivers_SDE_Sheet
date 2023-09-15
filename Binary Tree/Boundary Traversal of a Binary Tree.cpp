https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/











class Solution {
public:
  /*
   * This function traverses the left boundary of the binary tree and adds all the nodes to the `ans` vector.
   * The left boundary is defined as the path from the root to the leftmost node.
   */
  void traverseLeft(Node *root, vector<int> &ans) {
    if (root == NULL || !root->left && !root->right) {
      return;
    }
    ans.push_back(root->data);
    if (root->left) {
      traverseLeft(root->left, ans);
    } else {
      traverseLeft(root->right, ans);
    }
  }

  /*
   * This function traverses all the leaf nodes of the binary tree and adds them to the `ans` vector.
   */
  void traverseLeaf(Node *root, vector<int> &ans) {
    if (root == NULL) {
      return;
    }
    if (!root->left && !root->right) {
      ans.push_back(root->data);
      return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
  }

  /*
   * This function traverses the right boundary of the binary tree and adds all the nodes to the `ans` vector.
   * The right boundary is defined as the path from the root to the rightmost node.
   */
  void traverseRight(Node *root, vector<int> &ans) {
    if (root == NULL || !root->left && !root->right) {
      return;
    }
    if (root->right) {
      traverseRight(root->right, ans);
    } else {
      traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
  }

  /*
   * This function prints the boundary elements of the binary tree.
   * The boundary elements are the nodes on the left boundary, all the leaf nodes, and the nodes on the right boundary.
   */
  vector <int> boundary(Node *root) {
    // Your code here
    vector<int> ans;
    if (root == NULL) {
      return ans;
    }
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

/* traverseLeaf(root->left, ans) function calls itself recursively for both the left and right subtrees of the current node*/


    traverseRight(root->right, ans);
    return ans;
  }
};













#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = nullptr;
	return temp;
}

bool isLeaf(Node* node){
if(node->left == NULL && node->right==NULL){
	return true;
}
return false;
}

void addLeftBound(Node * root, vector<int>& ans){
//Go left left and no left then right but again check from left
root = root->left;
while(root){
	if(!isLeaf(root)) ans.push_back(root->data);
	if(root->left) root = root->left;
	else root = root->right;
}
}

void addRightBound(Node * root, vector<int>& ans){
//Go right right and no right then left but again check from right
root = root->right;
//As we need the reverse of this for Anticlockwise
//refer above picture for better understanding
stack<int> stk;
while(root){
	if(!isLeaf(root)) stk.push(root->data);
	if(root->right) root = root->right;
	else root = root->left;
}
while(!stk.empty()){
	ans.push_back(stk.top());
	stk.pop();
}
}

//its kind of preorder
void addLeaves(Node * root, vector<int>& ans){
if(root==NULL){
	return;
}
if(isLeaf(root)){
	ans.push_back(root->data); //just store leaf nodes
	return;
}
addLeaves(root->left,ans);
addLeaves(root->right,ans);
}

vector <int> boundary(Node *root)
{
//Your code here
vector<int> ans;
if(root==NULL) return ans;
if(!isLeaf(root)) ans.push_back(root->data); // if leaf then its done by addLeaf
addLeftBound(root,ans);
addLeaves(root,ans);
addRightBound(root,ans);

return ans;

}

int main()
{
	// Let us construct the tree given in the above diagram
	Node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	vector<int>ans = boundary(root);
	for(int v : ans){
		cout<<v<<" ";
	}
	cout<<"\n";

	return 0;
}

/*
Output
20 8 4 10 14 25 22 
Time Complexity: O(n) where n is the number of nodes in binary tree.
Auxiliary Space: O(n) 
*/
