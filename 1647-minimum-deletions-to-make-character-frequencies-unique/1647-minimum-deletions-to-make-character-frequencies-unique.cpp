class Solution {
public:
    int minDeletions(string s) {
        vector<int>c(26,0);
       int res = 0;
    for (auto x : s)
        ++c[x - 'a'];
    sort(begin(c), end(c));
    for (int i = 24; i >= 0 && c[i] > 0; --i) 
    {
        int x= max(0, c[i + 1] - 1);
        res += max(0, c[i] - x);
        c[i] = min(c[i], max(0, c[i + 1] - 1));
    }
    return res;
    }
};