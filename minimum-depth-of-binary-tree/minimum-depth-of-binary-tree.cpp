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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ht=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            ht++;
            int k=q.size();
             for(int i=0;i<k;i++)
             {
                   TreeNode *r=q.front();
                 if(r->left)
                     q.push(r->left);
                 if(r->right)
                     q.push(r->right);
                 q.pop();
                 if(r->left==NULL && r->right==NULL)
                     return ht;
             }
        }
        return 0;
    }
};
 