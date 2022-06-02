class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) {
     int n=v.size();
        int m=v[0].size();
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                res[j][i] = v[i][j];
        return res;
    }
};