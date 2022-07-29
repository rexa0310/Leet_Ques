class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
     vector<string> res;
        for (string w : w) 
            if (F(w) == F(p))
                res.push_back(w);
        return res;
    }

    string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
};