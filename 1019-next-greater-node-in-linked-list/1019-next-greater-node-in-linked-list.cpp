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
    vector<int> nextLargerNodes(ListNode* h)
    {
         vector<int> res, stack;
        while (h != nullptr)
        {
            res.push_back(h->val);
            h = h->next;
        }
        for (int i = res.size() - 1; i >= 0; --i)
        {
            int curr_e = res[i];
            while (!stack.empty() && stack.back() <= curr_e)
                stack.pop_back();
            res[i] = stack.empty()? 0: stack.back();
            stack.push_back(curr_e);

        }
        return res;   
    }
};