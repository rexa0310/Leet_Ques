class Solution {
public:
    int minimumEffort(vector<vector<int>>& v) {
      int res = 0;
        for (auto &x : v)
            x[0] = x[1] - x[0];
        sort(v.begin(), v.end());
        for (auto &x : v)
            res = max(res + x[1] - x[0], x[1]);
        return res;
    
    }
};