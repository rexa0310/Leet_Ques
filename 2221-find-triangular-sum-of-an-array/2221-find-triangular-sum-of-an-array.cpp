class Solution {
public:
    int triangularSum(vector<int>& v) {
         int n=v.size();
        while(n--)
        {
            for(int i=0;i<n;++i)
                v[i]=(v[i]+v[i+1])%10;
            
        }
        return v[0];
    }
};