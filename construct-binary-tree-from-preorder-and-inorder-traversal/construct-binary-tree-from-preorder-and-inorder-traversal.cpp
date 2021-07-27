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
 TreeNode* solver(vector<int>& preorder, vector<int>& inorder,int& pre_idx,int l,int r)       
            {
             if(l>r)
                 return NULL;
             
              int i=l;
              while(inorder[i]!=preorder[pre_idx])
                  i++;
              
             pre_idx++;
             TreeNode *newNode=new TreeNode(inorder[i]);
             newNode->left=solver(preorder,inorder,pre_idx,l,i-1);
             newNode->right=solver(preorder,inorder,pre_idx,i+1,r);
     
            return newNode;
     
         }
   
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_Idx = 0;
        return solver(preorder, inorder, pre_Idx, 0, inorder.size()-1);
    }
};
    
