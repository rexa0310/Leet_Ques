class Solution {
public:
    string shiftingLetters(string s, vector<int>& v) {
      int n=s.length();
       int x = 0;
        for (int i=n-1;i>=0;--i) {
            x = (x + v[i]) % 26;
            s[i] = (s[i] - 'a' + x) % 26 + 'a';
        }
        return s;
    }
};