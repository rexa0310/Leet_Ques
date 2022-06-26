class Solution {
public:
      int m, n;
    int dp[1000][1000];
    int maximumScore(vector<int>& v, vector<int>& x) {
        n = v.size();
        m = x.size();
        // memset(dp, -1, sizeof(dp));
        for(int i=0;i<1000;i++)
            for(int j=0;j<1000;j++)
                dp[i][j]=-100001;
        return solve(0, 0, v, x);
    }
    int solve(int l, int i, vector<int>& v, vector<int>& x) {
        if (i == m) 
            return 0; 
        if (dp[l][i] != -100001)
            return dp[l][i];
        int ls = solve(l+1, i+1, v, x) + v[l] * x[i];
        int rs = solve(l, i+1, v, x) + v[n-(i-l)-1] * x[i]; 
        
        return dp[l][i] = max(ls, rs);
    }
};