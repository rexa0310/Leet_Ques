class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& v)
    {
     int n=v.size();
        for(int i=0;i<n;i++)
            v[i]%=60;
        int c=0;
        vector<int>m(121,0);
        for(auto x:v)
        {
            c+=m[60-x];
            m[x]++;
            m[x+60]++;
           // cout<<x<<" ";
        }
        return c;
    }
};