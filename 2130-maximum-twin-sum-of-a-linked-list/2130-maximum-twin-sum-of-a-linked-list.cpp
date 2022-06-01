/**
 * Definititemp for singly-linked list.
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
    ListNode* middleNode(ListNode* head) {
    struct ListNode *slow, *fast;
    slow=head;
    fast=head->next;
    
    while(slow!=NULL && fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=NULL) 
            fast=fast->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head)
{
    ListNode *p, *q;
    p=head, q=NULL;
    
    while(p!=NULL)
    {
        ListNode *temp=p->next;
        p->next=q;
        q=p;
        p=temp;
    }
    return q;
}

int pairSum(ListNode* head) 
{
    ListNode *mid=middleNode(head);
    
    ListNode *p=head, *q=reverseList(mid->next);
    mid->next=NULL;
    
    int ans=0;
    while(p!=NULL && q!=NULL)
    {
        ans = max(ans,p->val+q->val);
        p=p->next, q=q->next;
    }
    
    return ans;
}
        
    
};