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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
          helper(root, 0);
        return lca;
    }
     TreeNode* lca ;
    int ht = 0;
   
    int helper(TreeNode* node, int depth) {
        ht = max(ht, depth);
        if (!node) {
            return depth;
        }
        int left = helper(node->left, depth + 1);
        int right = helper(node->right, depth + 1);
        if (left == ht && right == ht) {
            lca = node;
        }
        return max(left, right);
    }
};