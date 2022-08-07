class Solution {
public:
    const int mod = 1e9+7;
    map<char,int>m;
    int dp[20001][5];
    int solve(char prev, int idx, int n){
        if(idx == n-1)
        {
            return 1;
        }
        
        if(dp[idx][m[prev]] != -1)
        {
            return dp[idx][m[prev]];
        }
        
        int ans = 0;
        if(prev == 'a')
        {
            ans = solve('e', idx+1, n)%mod;
        }
        
        else if(prev == 'e')
        {
            ans = (solve('a', idx+1, n)%mod + solve('i', idx+1, n)%mod)%mod;
        }
        
        else if(prev == 'i')
        {
       ans = (((solve('a', idx+1, n)%mod + solve('e', idx+1, n)%mod)%mod + solve('o', idx+1, n)%mod)%mod + solve('u', idx+1, n)%mod)%mod;
        }
        
        else if(prev == 'o')
        {
            ans+=(solve('i', idx+1, n)%mod + solve('u', idx+1, n)%mod)%mod;
        }
        
        else if(prev == 'u')
        {
            ans+=solve('a', idx+1, n)%mod;
        }
        
        return dp[idx][m[prev]] = ans%mod;
    }
    
    int countVowelPermutation(int n) {
     vector<char>v={'a','e','i','o','u'};
        // cout<<dp[0][1]<<endl;
        memset(dp, -1,sizeof(dp));
        int c=0;
        for(auto x:v)
            m[x]=c,c++;
        
         int ans = 0;
        for(auto x: v)
        {
            ans = (ans%mod + solve(x, 0, n)%mod)%mod;
        }
        return ans;
        
    }
};