class Solution {
public:
    vector<vector<int>>v1;
    int n;
    int dp[41][1025];
    const int mod = 1e9+7;
    
    int solve(int i, int mask)
    {
        if(mask == (1<<n)-1)
            return 1;
        
        if(i>40)
            return 0;
        
        if(dp[i][mask]!=-1)
            return dp[i][mask];
        
        int op1 = solve(i+1,mask); 
        int op2 = 0;
        for(auto person : v1[i])
        {
            if(mask&(1<<person))
                continue;
            op2 = (op2 % mod + solve(i+1,mask+(1<<person)) % mod) % mod;
        }
        return dp[i][mask] = (op1 % mod + op2 % mod) % mod;
    }
    
    int numberWays(vector<vector<int>>& v) 
    {
        v1.resize(41);
        memset(dp,-1,sizeof(dp));
        
        n = v.size();
        for(int i=0; i<n; i++)
        {
            for(auto hat : v[i])
                v1[hat].push_back(i);
        }
        
        int ans = solve(0,0);
        
        return ans;
    }
};