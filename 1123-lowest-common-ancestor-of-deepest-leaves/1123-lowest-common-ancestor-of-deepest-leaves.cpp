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
    private:
      TreeNode* lca;
    int ht = 0;
public:
 
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    
    {
        helper(root, 0);
        return lca;
    }

    int helper(TreeNode* node, int cur_ht) {
        ht = max(ht, cur_ht);
        if (node==NULL) 
            return cur_ht;
        
         ht = max(ht, cur_ht);
        int left = helper(node->left, cur_ht + 1);
        int right = helper(node->right, cur_ht + 1);
        if (left == ht && right == ht) 
            lca = node;
        
        return max(left, right);
    }
};