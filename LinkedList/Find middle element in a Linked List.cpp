https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};

/*
Time Complexity: O(N)

Space Complexity: O(1)
*/

