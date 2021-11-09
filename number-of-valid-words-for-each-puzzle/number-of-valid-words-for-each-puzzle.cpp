class Solution {
    int getMask(string & s) {
        int mask = 0;
        for (auto c: s)
            mask |= (1<<(c-'a'));
        return mask;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        for (auto & w: words) {
            int mask = getMask(w);
            freq[mask] ++;
        }
        vector<int> res;
        for (auto & p : puzzles) {
            int mask = getMask(p);
            int cnt = 0;
            int maskFirstChar = 1<<(p[0]-'a');
            for (int i = mask; i > 0; i = ((i-1) & mask)) {
                if ((i & maskFirstChar) > 0 && freq.count(i)) {
                    cnt += freq[i];
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};