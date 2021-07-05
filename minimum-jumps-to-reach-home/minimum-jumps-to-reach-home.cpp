class Solution {
public:
    
     unordered_map<int,int>m;
    int dp[7001][2];
    int solve(int start,bool check_twice,int a,int b,int target)
    {
        
        if(start==target)
            return 0;
        
         if( start < 0 || m.find(start)!= m.end() || start>6000 )
            return 1e9;
        
        
        if(dp[start][check_twice]!=-1)
           return dp[start][check_twice];
        int forward = 0;
       
        dp[start][check_twice] = 1 + solve(start+a,0,a,b,target);
        if(!check_twice)
        {
            dp[start][check_twice] = min(dp[start][check_twice],1 + solve(start-b,1,a,b,target));
        }
      
        return dp[start][check_twice];
    }
        
        
        
        
        
    int minimumJumps(vector<int>& v, int a, int b, int x) 
    {
            for(int i = 0 ; i<v.size();i++)
            m[v[i]] = 1;
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,a,b,x);
        if(ans > 1e9)
            return -1;
        return ans;
    }
};