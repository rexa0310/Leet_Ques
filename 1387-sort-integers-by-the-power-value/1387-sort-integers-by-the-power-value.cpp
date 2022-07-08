class Solution {
public:
      vector<int>dp;
    int calc(int i)
    {
        if(i==1)
            return 0;
        
        if(i<dp.size() and dp[i]!=-1)
            return dp[i];
        
        int x = 0;
        if(i%2)
            x = 1+calc(3*i+1);
        else
            x = 1+calc(i/2);
        
        if(i<dp.size())
            dp[i] = x;
        return x;
    }
    
    int getKth(int lo, int hi, int k) 
    {
        dp.resize(1001,-1);
        vector<pair<int,int>>x;
        for(int i=lo; i<=hi; i++)
            x.push_back(make_pair(calc(i),i));
        
        sort(x.begin(),x.end());
        return x[k-1].second;
        
    }
};