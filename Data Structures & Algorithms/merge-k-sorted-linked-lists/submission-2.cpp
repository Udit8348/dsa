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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using Entry = pair<int, ListNode*>; // {value, node memory address}

        priority_queue<Entry, vector<Entry>, greater<>> pq;

        // collect valid list heads
        for (ListNode* l : lists) {
            if (l != nullptr) {
                pq.emplace(l->val, l);
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        // consume ordered list heads and traverse
        while (!pq.empty()) {
            // get list head with smallest value
            auto [val, incoming] = pq.top();
            pq.pop();

            // insert to result
            curr->next = incoming;
            curr = curr->next;

            // move list head to next and insert if valid
            incoming = incoming->next;
            if (incoming != nullptr) {
                pq.emplace(incoming->val, incoming);
            }
        }

        return head->next;
    }
};
