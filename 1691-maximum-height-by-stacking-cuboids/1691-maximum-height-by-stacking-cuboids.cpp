class Solution {
public:
    int maxHeight(vector<vector<int>>& v) {
        int n = v.size();
        for (auto &c : v)
            sort(c.begin(), c.end());
        
        sort(v.begin(), v.end());
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {   
            dp[i] = v[i][2];
          for (int j = 0; j <= i - 1; j++)
            {
         if ((v[i][0] >= v[j][0]) && (v[i][1] >= v[j][1]) && (v[i][2] >= v[j][2]))
                {
                    dp[i] = max(dp[i], dp[j] + v[i][2]);
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};