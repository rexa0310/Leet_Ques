class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& v) {
        map<pair<long,long>,long long> m;
        for(auto x: v)
        {
            
            long long w= x[0];
            long long h = x[1];
            long long d= __gcd(w,h);
            w = w/d;
            h = h/d;
            m[{w,h}]++;
            
        }
        long long ans = 0;
        for(auto x : m)
            ans += (x.second*(x.second-1))/2; 
        
        return ans; 
    }
};