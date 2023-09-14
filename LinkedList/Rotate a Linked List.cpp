//Rotate a Linked List by left k positions

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
    if (!head || k == 0) {
        return head;
    }

    // Calculate the length of the linked list
    int length = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Calculate the actual rotation position (k % length)
    k = k % length;

    if (k == 0) {
        return head; // No rotation needed
    }

    // Find the (k-1)th and kth nodes
    Node* kthNode = head;
    Node* prevKthNode = nullptr;
    for (int i = 0; i < k; i++) {
        prevKthNode = kthNode;
        kthNode = kthNode->next;
    }

    // Update pointers to perform rotation
    prevKthNode->next = nullptr;
    tail->next = head;
    head = kthNode;

    return head;
    }
};




//Rotate a Linked List by right k positions


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};
