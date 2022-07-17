class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
    
        vector<int> in(n);
        for (int i = 0; i < n; i++)
        if ((lc[i] >= 0 and ++in[lc[i]] > 1) or (rc[i] >= 0 and ++in[rc[i]] > 1))
                return false;
        
        int rt = -1;
        for (int i = 0; i < n; i++)
            if (!in[i])
            {
                if (rt == -1)
                    rt = i;
                else
                    return false;
            }
     
        return cnt(lc, rc, rt) == n;
    }
    
    int cnt(vector<int> &left, vector<int> &right, int rt) 
    {
        if (rt == -1)
            return 0;
        return 1 + cnt(left, right, left[rt]) + cnt(left, right, right[rt]);
      
    }
};