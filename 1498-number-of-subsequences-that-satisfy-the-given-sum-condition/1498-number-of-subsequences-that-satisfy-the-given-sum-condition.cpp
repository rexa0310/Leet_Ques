class Solution {
public:
    int numSubseq(vector<int>& v, int k) {
        sort(v.begin(),v.end());
    int mod=1e9+7,s=0;
        int i=0,j=v.size()-1;
        vector<int>p(v.size()+1,1);
        for(int i=1;i<=v.size();i++)
        {
            p[i]=(p[i-1]*2)%mod;
        }
        while(i<=j)
        {
            if(v[i]+v[j]<=k)
            {
                s=(s+p[j-i])%mod;
                i++;
            }
            else
                j--;
            
        }
        return s;
    }
};