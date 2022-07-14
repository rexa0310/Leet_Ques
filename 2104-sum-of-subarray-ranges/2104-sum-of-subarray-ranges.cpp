class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
      long long res = 0;
        for (int i = 0; i < v.size(); i++) {
            int ma = v[i], mi = v[i];
            for (int j = i; j < v.size(); j++) {
                ma = max(ma, v[j]);
                mi = min(mi, v[j]);
                res += ma - mi;
            }
        }
        return res;   
    }
};