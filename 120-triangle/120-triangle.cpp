class Solution {
public:
    int minimumTotal(vector<vector<int>>& v)
    {
          vector<int> dp = v[v.size()-1];
        for ( int i = v.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < v[i].size() ; ++ j )
                dp[j] = v[i][j] + min(dp[j],dp[j+1]);
        
        
        return dp[0];
    }
};