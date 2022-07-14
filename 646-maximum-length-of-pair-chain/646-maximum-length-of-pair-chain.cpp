class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
         if(!v.size()) 
             return 0;
        sort(v.begin(), v.end());
		
        vector<int> dp(v.size(), 1);
        int ans=1;
		
        for(int i=1;i<v.size();i++)
        {
            for(int j=0;j<i;j++)
            {	
                if((v[j][1] < v[i][0]) && (dp[i] < dp[j] + 1))
                {
                    dp[i] = dp[j] + 1;
                    ans=max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};