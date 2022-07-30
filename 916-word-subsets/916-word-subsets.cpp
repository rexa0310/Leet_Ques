class Solution {
public:
       vector<int> solve(string& word) 
       {
        vector<int> c(26);
        for (char x : word) 
            c[x- 'a']++;
        return c;
    }
    
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
         vector<int> c(26), tmp(26);
        int i;
        for (string b : w2) 
        {
            tmp = solve(b);
            for (i = 0; i < 26; ++i)
                c[i] = max(c[i], tmp[i]);
        }
        
        vector<string> res;
        for (string a : w1)
        {
            tmp = solve(a);
            for (i = 0; i < 26; ++i)
                if (tmp[i] < c[i])
                    break;
            if (i == 26) 
                res.push_back(a);
        }
        return res;
    }
};