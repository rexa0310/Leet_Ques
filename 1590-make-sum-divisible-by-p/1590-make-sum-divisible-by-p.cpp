class Solution {
public:
    int minSubarray(vector<int>&v, int k) {
        int n = v.size(), res = n, s = 0;
        for (auto x : v)
            s = (s + x) % k;
        
        map<int, int> m = {{0, -1}};
        
        int s1=0;
        for (int i = 0; i < n; ++i) 
        {
            s1 = (s1 + v[i]) % k;
            m[s1] = i;
            int x = (s1 - s + k) % k;
            if (m.count(x))
                res = min(res, i - m[x]);
        }
        
        if(res<n)
            return res;
        return -1;
    }
};