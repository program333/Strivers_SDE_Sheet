https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/



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
