class Solution {
public:
    long long numberOfWays(string s) {
          int len = s.size();
        vector<int> left_ones(len);
        vector<int> left_zeros(len);
        vector<int> right_ones(len);
        vector<int> right_zeros(len);
        
        for (int i = 1; i < len; ++i) {
            left_ones[i] = left_ones[i - 1] + (s[i - 1] == '1');
            left_zeros[i] = left_zeros[i - 1] + (s[i - 1] == '0');
        }
        
        for (int i = len - 2; i >= 0; --i) {
            right_ones[i] = right_ones[i + 1] + (s[i + 1] == '1');
            right_zeros[i] = right_zeros[i + 1] + (s[i + 1] == '0');
        }
        
        long long res = 0;
        for (int i = 1; i < len - 1; ++i) {
            if (s[i] == '0') {
                res += left_ones[i] * right_ones[i];
            } else {
                res += left_zeros[i] * right_zeros[i];
            }
        }
        
        return res;
    }
};