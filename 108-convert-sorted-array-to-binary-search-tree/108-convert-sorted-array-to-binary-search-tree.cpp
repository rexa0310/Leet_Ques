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
    TreeNode* convert(vector<int>& nums,int left,int right)
    {
        if(right<=left)
            return NULL;
        int mid=(left+right)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left= convert(nums,left,mid);
        root->right=convert(nums,mid+1,right);
        
        return root;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
     return convert(nums,0,nums.size());    
    }
};