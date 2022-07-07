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
    unordered_map<int,int>m;
    int ans=INT_MIN,mx;
    void dfs(TreeNode* root, int x)
    {
        if(root==NULL)
            return;
        m[x]+=root->val;
         // if(m[x]>ans)
         // {
         //     ans=m[x];
         //     mx=x;
         // }
       // cout<<m[x]<<" "<<x<<endl;
        dfs(root->left,x+1);
        dfs(root->right,x+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        for(auto x:m)
        {
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second>=ans)
            {
                ans=x.second;
                mx=x.first;
            }
        }
        return mx;
        
    }
};