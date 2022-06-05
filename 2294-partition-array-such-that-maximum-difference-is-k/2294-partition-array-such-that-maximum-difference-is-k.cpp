class Solution {
public:
    int partitionArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int c = 1, mn = v[0], mx = v[0];
        for (int x: v)
        {
            mn = min(mn, x);
            mx = max(mx, x);
            if (mx - mn > k)
            {
                c++;
                mn = mx = x;
            }
        }
        return c;
    
    }
};