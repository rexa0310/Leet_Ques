class Solution {
public:
    int numberOfWays(string s) {
        int mod=1e9+7;
        int n=s.length();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='S')
                v.push_back(i);
        }
        
        if(v.size()==0 || v.size()%2==1)
            return 0;
        
        int prev=v[1];
        long long sum=1;
        for(int i=2;i<v.size();i+=2)
        {
            long long l=(v[i]-prev);
            sum=(sum*l)%mod;
            prev=v[i+1];
        }
        return sum;
    }
};