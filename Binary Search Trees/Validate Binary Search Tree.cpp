https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
public:
     void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }
   
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        
        inOrder(root);
        for (int i=1; i<tree.size(); i++)
            if (tree[i] <= tree[i-1])
                return false;
        return true;
    }
private:
    vector<int> tree;
};
