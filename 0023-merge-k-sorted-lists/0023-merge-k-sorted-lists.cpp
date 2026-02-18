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


 class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        }

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();

            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }

            if (temp->next) {
                pq.push(temp->next);
            }
        }

        return head;
    }
};
