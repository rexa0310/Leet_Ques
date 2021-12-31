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
    
    int dfs(TreeNode*root,int mn,int mx)
    {
        if(root==NULL)
            return 0;
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        int lefty=dfs(root->left,mn,mx);
        int righty=dfs(root->right,mn,mx);
        return max(mx-mn,max(lefty,righty));
    }
    int maxAncestorDiff(TreeNode* root) {
        int s=dfs(root,root->val,root->val);
        return s;
    }
};