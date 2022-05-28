class Solution {
public:
    int minMoves2(vector<int>& v) {
        int n=v.size();
        if(n==1)
            return 0;
        if(n==2)
            return abs(v[0]-v[1]);
        sort(v.begin(),v.end());
        if(n%2)
        {
            long long s=0;
            long long x=v[n/2];
            for(auto i:v)
                s+=abs(i-x);
            return s;
        }
        long long x=v[n/2],y=v[n/2 +1];
        long long s=0,s1=0;
        for(auto i:v)
        {
            s+=abs(i-x);
            s1+=abs(i-y);
            
        }
        return min(s,s1);
    }
};