https://www.geeksforgeeks.org/zigzag-tree-traversal/
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> result;
            if (root == nullptr) {
                return result;
            }

            queue<TreeNode*> q;
            q.push(root);

            bool flag = false ;  
            while (!q.empty()) {
                   int size = q.size() ;
                    vector<int> level ;
                    for(int i=0 ; i < size ; i++){
                        TreeNode* node = q.front() ;
                        q.pop() ;
                        level.push_back(node->val) ;
            
                        if(node->left != NULL) {q.push(node->left) ;}
                        if(node->right != NULL) {q.push(node->right) ;}   
            
                    }
                    flag = !flag ;  
                    if(flag == false){
                        reverse(level.begin() , level.end()) ;           
                    }
                result.push_back(level);      
            }

            return result;
            
    }
};
