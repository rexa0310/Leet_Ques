   class Solution {
public:
    const int INF = INT_MAX;
    vector<vector<int>> dp;
    vector<int> pre;
       
    
    int sum(int l, int r)
    {
        return pre[r + 1] - pre[l];
    }
    int solve(int l, int r) 
    {
        if (l == r)
            return 0;
        if (dp[l][r] != INF) 
            return dp[l][r];
        
        int ls = sum(l + 1, r);
        int rs = sum(l, r - 1);
        
        int ans = max(ls - solve(l + 1, r), rs - solve(l, r - 1));
        return dp[l][r] = ans;
    }
       
       int stoneGameVII(vector<int>& stones) 
    {
        int n = stones.size();
        dp.resize(n, vector<int>(n, INF));
        pre.resize(n + 1, 0);
        
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stones[i];
        
        return solve(0, n - 1);
    }
};