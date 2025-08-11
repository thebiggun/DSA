class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        
        // Check if there are at least k nodes
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        
        if (count == k) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* nextNode = NULL;
            int i = 0;
            
            // Reverse first k nodes
            while (i < k) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                i++;
            }
            
            // Recursively reverse the rest
            head->next = reverseKGroup(curr, k);
            
            return prev; // New head of this reversed group
        } 
        else {
            return head; // Less than k nodes, leave as is
        }
    }
};
