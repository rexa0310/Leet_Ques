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
    
    void solve(TreeNode * root,vector<int>& cur, vector<vector<int>>&res,int target)
    {
        if(root==NULL)
            return ;
        cur.push_back(root->val);
         if(root->right==NULL && root->left==NULL && root->val==target)
             res.push_back(cur);
        solve(root->left,cur,res,target- root->val);
        solve(root->right,cur,res,target -root->val);
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int>cur;
        vector<vector<int>>res;
        solve(root,cur,res,target);
        return res;
    }
};