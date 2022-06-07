class Solution {
public:
    long long dp[100005];
	
    int search(vector<vector<int>>& v,int val)
    {
        int s=0,e=v.size()-1;
        int ans=v.size();
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(v[mid][0]>=val)
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
    
    long long helper(int i,vector<vector<int>>& v)
    {
        if(i==v.size())
        {
            return 0;
        }
        if(dp[i]!=-1) 
            return dp[i];
        long long op1 = helper(i+1,v);  
        int idx = search(v,v[i][1]); 
        long long op2 = v[i][1]-v[i][0] + v[i][2] + helper(idx,v); 
        return dp[i]=max(op1,op2);
    }
    
    
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& v) {
        memset(dp,-1,sizeof dp);
        sort(v.begin(),v.end());
        return helper(0,v);
    }
};