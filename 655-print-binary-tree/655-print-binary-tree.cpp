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
     int getHeight(TreeNode* root)
     
     {
        if(!root)return 0;
        return 1+max(getHeight(root->left), getHeight(root->right));
    }
    void dfs(TreeNode *node, int row, int column, int height, vector<vector<string>> &ans)
    {
        if(!node)
            return;
        
        ans[row][column] = to_string(node->val);
        dfs(node->left, row+1, column - pow(2, height-row-1), height, ans);
        dfs(node->right, row+1, column + pow(2, height-row-1), height, ans);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getHeight(root);
        int n = pow(2, m) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        dfs(root, 0, (n-1)/2, m-1, ans);
        return ans;
        
    }
};