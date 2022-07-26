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
    TreeNode* lca(TreeNode *root, int st, int dst) {
        if(!root) 
            return NULL;
        if(root->val == st) 
            return root;
        if(root->val == dst)
            return root;
        auto l = lca(root->left, st, dst);
        auto r = lca(root->right, st, dst);
        if(l && r) 
            return root;
        return l ? l : r;
    }
    bool getPath(TreeNode *root, int value, string &s) 
    {
        if(!root)
            return false;
        if(root->val == value) 
            return true;
        s += 'L';
        auto res = getPath(root->left, value, s);
        if(res)
            return true;
        s.pop_back();
        s += 'R';
        res = getPath(root->right, value, s);
        if(res) 
            return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int st, int dst) {
        root = lca(root, st, dst);
        string p1, p2;
        getPath(root, st, p1);
        getPath(root, dst, p2);
        for(auto &c : p1)
            c = 'U';
        return p1 + p2;
        
    }
};