

class Solution
{
    public:
    // Function to reverse a given linked list
Node* reverseList( Node *head)
{
     Node* prev = NULL;
     Node* current = head;
     Node* next;
 
    // traverse the list
    while (current)
    {
        // tricky: note the next node
        next = current->next;
 
        // fix the current node
        current->next = prev;
 
        // advance the two pointers
        prev = current;
        current = next;
    }
 
    // fix the head pointer to point to the new front
    head = prev;
}


    Node* addOne(Node *head) 
    {
       Node *temp=head,*curr=NULL,*prev_curr;
        curr=reverseList(temp);
        
        Node* curr_root=curr;
        while(curr!=NULL)
        {
            if(curr->data!=9)
            {
                curr->data=curr->data+1;
                break;
            }
            else
                curr->data=0;
                
            prev_curr=curr;
            curr=curr->next;
        }
        if(curr==NULL)
            curr=new Node(1),prev_curr->next=curr;

        return reverseList(curr_root);
      
        
    }
};
