class Solution {
public:
    int maxProfit(vector<int>& v)      
    {
         int ans=0;
        for(int i=1;i<v.size();i++)
            ans+=max(0,v[i]-v[i-1]);
    
    return ans;
    }
};