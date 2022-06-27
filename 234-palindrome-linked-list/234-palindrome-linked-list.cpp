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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast = head, *start = head;
        //finding the middle element
        while (fast!=NULL)
        {
            if (fast->next==NULL)
                break;
            
            fast = fast->next->next;
            slow = slow->next;
            
        }
        //revrsing the first half of the ll.
        ListNode *tmp, *prev = NULL;
        while (start!=slow)
        {
            tmp = start->next;
            start->next = prev;
            prev = start;
            start = tmp;
        }
        
        if (fast!=NULL)
            slow = slow->next;
        
        start = prev;
        
        //comparing for palindromice list
        while (slow != NULL)
        {
            if (start->val!=slow->val)
                return false;
            
            start = start->next;
            slow = slow->next;
        }
        return true;
    }
};