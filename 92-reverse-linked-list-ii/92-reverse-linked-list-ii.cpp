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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
   ListNode *temp = new ListNode(0), *pre = temp, *cur;
       temp-> next = head;
        
       for (int i = 0; i < l - 1; i++) 
           pre = pre -> next;
       cur = pre -> next;
        
       for (int i = 0; i < r-l; i++)
       {
           ListNode* temp1 = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp1;
       }
       return temp -> next;
   }
};