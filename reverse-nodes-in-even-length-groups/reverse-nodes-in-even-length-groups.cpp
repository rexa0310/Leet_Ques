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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
          int n = 0; 
        for (ListNode* node = head; node; node = node->next, ++n); 
        
        ListNode* node = head; 
        for (int k = 1; n; ++k) {
            int size = min(k, n); 
            stack<int> stk; 
            if (size % 2 == 0) {
                ListNode* temp = node; 
                for (int i = 0; i < size; ++i) {
                    stk.push(temp->val); 
                    temp = temp->next; 
                }
            }
            for (int i = 0; i < size; ++i) {
                if (stk.size()) node->val = stk.top(), stk.pop(); 
                node = node->next; 
            }
            n -= size; 
        }
        return head; 
    }
};