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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>>res;
        if(root==NULL) 
            return res;
        queue<TreeNode*>q;
        q.push(root);
        int ulta=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v(n);
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                q.pop();
                
                int id;
                if(ulta==0)
                    id=i;
                else
                    id=n-i-1;
                
                v[id]=x->val;
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                
            }
            ulta=1-ulta;
            res.push_back(v);
        }
        return res;
    }
};