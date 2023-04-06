https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
};

/*
Time complexity: O(N) where n is the number of nodes.

Space complexity: O(N), auxiliary space.
*/
