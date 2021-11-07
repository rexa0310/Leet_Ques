class Solution {
public:
    int singleNumber(vector<int>& v)
    {
        int n=v.size();
        long ans=0;int p=0,x;
        
        for(int i=0;i<32;i++)
        {
            int t=0;
            for(int j=0;j<n;j++)
            {
                x=v[j]&1;
                t+=x;
                v[j]>>=1;
            }
            
            t%=3;
            ans=ans+t*pow(2,p);
            p++;
        }
        
        return ans;
    }
};