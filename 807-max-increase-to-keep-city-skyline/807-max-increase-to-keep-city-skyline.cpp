class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& v) {
        int n = v.size(), s = 0;
        vector<int> r(n), c(n);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                r[i] = max(r[i], v[i][j]);
                c[j] = max(c[j], v[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                s += min(r[i], c[j]) - v[i][j];
            }
        }
        
        return s;
    }
};