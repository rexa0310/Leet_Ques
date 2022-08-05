class Solution {
public:
    int combinationSum4(vector<int>& v, int t) {
          vector<unsigned int> dp(t+1, 0);
        dp[0] = 1;
        for (int i = 0; i < t; i++) 
        {
            if (!dp[i])
                continue;
            for (int x : v)
                if (x + i <= t) 
                    dp[i+x] += dp[i];
        }
        return dp[t];
    }
};