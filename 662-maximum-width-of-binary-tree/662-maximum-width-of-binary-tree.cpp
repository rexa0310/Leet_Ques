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
    int widthOfBinaryTree(TreeNode* root) {
       int ans=0;
        queue<pair<TreeNode*,int>> q;  
        q.push({root,0});
        
        while(!q.empty())
        {
            int sz=q.size();     
            int end;
            int fir=q.front().second;

            for(int i=0; i<sz; i++)
            {
                TreeNode* node=q.front().first;
                long long int cur=q.front().second; 
                
                cur=cur-fir;          
                q.pop();             
                
                if(i==sz-1)          
                    end=cur;
                
                if(node->left)
                    q.push({node->left,2*cur+1});
                if(node->right)
                    q.push({node->right,2*cur+2});  
            }
            ans=max(ans,end+1);   
        }
        return ans;
      
    }
};