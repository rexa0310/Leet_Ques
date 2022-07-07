/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<string, int> mp;
    vector<TreeNode*> ans;
    string dfs(TreeNode *p)
    {
        if(!p) 
            return "";
        string res = to_string(p->val) + "|" + dfs(p->left) + "|" + dfs(p->right);
        mp[res] ++;
        
        if(mp[res] == 2) 
            ans.push_back(p);
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        dfs(root);
        return ans;
        
    }
};