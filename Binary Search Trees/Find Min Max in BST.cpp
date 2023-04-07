https://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/


int minValue(Node* root) {
    // Code here
    if(root==NULL){
        return -1;
    }
    Node *temp=root;
    while(temp->left!= NULL){
        temp=temp->left;
    }
    
    return (temp->data);
}
