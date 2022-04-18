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
class Solution 
{
    int c=0,x=-1;
public:
    void inorder(TreeNode* root, int k)
    {
        if (root==NULL)return;
        inorder(root->left, k);
        c++;
        if(c==k)
            x=root->val;
        inorder(root->right, k);
        
    }
    int kthSmallest(TreeNode* root, int k)
    {
        
        inorder(root,k);
        return x;
    }
};