/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (curr == NULL) {
                return head;
            } else {
                curr = curr->next;
            }
        }
        ListNode* prev = NULL;
        curr = head;
        ListNode* forward;
        for (int i = 0; i < k; i++) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};