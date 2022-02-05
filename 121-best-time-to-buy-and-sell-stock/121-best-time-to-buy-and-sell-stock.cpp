class Solution {
public:
    int maxProfit(vector<int>& v) {
         int m=100000,ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<m)
                m=v[i];
            ans=max(ans,v[i]-m);
        }
        return ans;
    }
};