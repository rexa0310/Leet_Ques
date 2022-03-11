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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        
        int l=1;
        ListNode * temp=head,*h1=head;
        while(temp->next)
        {
            l++;
            temp=temp->next;
        }
        
         temp->next = head; 

        if(k %= l) 
            for(int  i=0; i<l-k; i++) 
                temp = temp->next; 
        h1 = temp->next; 
        temp->next = NULL;
        return h1;
    }
};