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
    int sum=0;
     void dfs(TreeNode* root,int cur)
    {
        cur=cur*10+root->val;
        if(!root->left && !root->right)
            sum+=cur;
        if(root->left)
            dfs(root->left,cur);
        if(root->right)
            dfs(root->right,cur);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root,0);
        return sum;
    }
   
};