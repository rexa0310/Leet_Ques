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
    vector<TreeNode*>res;
    unordered_set<int>s;
    TreeNode* dfs(TreeNode* root,bool pa)
    {
      if(root ==NULL)
          return NULL;
        bool check=false;
        if(s.find(root->val)!=s.end())
             check=true;
        if(pa==true && check==false)
            res.push_back(root);
        
        root->left=dfs(root->left,check);
        root->right=dfs(root->right,check);
        if(check==true)
            return NULL;
        return root;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& v) {
        for(int i=0;i<v.size();i++)
            s.insert(v[i]);
        dfs(root,true);
        return res;
    }
};