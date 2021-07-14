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
      vector<TreeNode*> v;
    
        
        void Inorder( TreeNode *root)
        {
            if(root)
            {
                Inorder(root->left);
                v.push_back(root);
                Inorder(root->right);
            }
        }    
    
        void recoverTree(TreeNode* root) 
        {
            Inorder(root);
            
            int i, j;
            for(i=0; i<v.size()-1; i++)
                if(v[i]->val > v[i+1]->val)
                    break;
            
            for(j=i+1; j<v.size()-1; j++)
                if(v[j]->val > v[j+1]->val)
                    break;
            
             j++;
            
            if(j == v.size())
                j = i+1;
           swap(v[i]->val, v[j]->val);
    }
};