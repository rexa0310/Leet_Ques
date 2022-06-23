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
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int x=1+maxDepth(root->left);
        int y=1+maxDepth(root->right);
        return max(x,y);
        
    }
    int ans=-1,res=0;
    void solve(TreeNode* root,int ht ,int x)
    {
        if(x==ht && res==0)
         {
           ans=root->val;
            res++;
           return;
        
        }
        if(root->left)
            solve(root->left,ht,x+1);
       
        if(root->right)
            solve(root->right,ht,x+1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ht=maxDepth(root);
      
         solve(root,ht,1);
        return ans;
    }
};