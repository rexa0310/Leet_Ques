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
    ListNode* deleteDuplicates(ListNode* head)
    {
         ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int flag = true;
        while(head)
        {
            while(head && head->next && head->val==head->next->val)
            {
                flag = false; 
                head = head->next;
            }
            if(flag) 
            {
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
            flag = true; 
        }
        tail->next = nullptr;
        return dummy->next;
        
    }
};
