https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
https://leetcode.com/problems/search-in-a-binary-search-tree/description/


bool search(Node* root, int x) {
    // Your code here
    while(root!=NULL){
        if(root->data==x)
            return true;
        else if(root->data<x)
            root=root->right;
        else
            root=root->left;
    }
    return false;
}


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       if(root==NULL || root->val == val){
                 return root;
       }

       if(root->val > val){
           root = searchBST(root->left, val);
       }
       else{
           root = searchBST(root->right,val);
       }
     return root;
    }
};
