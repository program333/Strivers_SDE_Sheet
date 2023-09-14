


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        if (!head)
		return NULL;
        int count=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(temp!=NULL && count<k){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        if(next != NULL){
            head->next = reverseKGroup(next,k);
        }

        return prev;
    }
};
