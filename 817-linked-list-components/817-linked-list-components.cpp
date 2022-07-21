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
    int numComponents(ListNode* head, vector<int>& v) {
        unordered_set<int> s;
         int c = 0;
    
    for(auto n:v)
        s.insert(n);
    
    while(head) 
    {
        if (s.count(head->val)&&(head->next==NULL||!s.count(head->next->val)))
            c++;
        head = head->next;
    }   
    return c;
    }
};