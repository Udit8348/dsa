class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // preprocess with a monotonic non-increasing stack, mark nodes for removal using negative
        stack<ListNode*> st;
        ListNode* curr = head;

        while (curr) {
            while (!st.empty() && st.top()->val < curr->val) {
                st.top()->val *= -1;
                st.pop();
            }
            st.push(curr);
            curr = curr->next;
        }

        ListNode sent = ListNode(0);
        ListNode* reader = head;
        ListNode* writer = &sent;

        while (reader) {
            if (reader->val > 0) {
                writer->next = reader;
                writer = writer->next;
            }
            reader = reader->next;
        }

        return sent.next;
    }
};
