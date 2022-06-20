class Solution {
public:
    int minimumLengthEncoding(vector<string>& s1) {
         unordered_set<string> s(s1.begin(), s1.end());
        for (string w : s)
            for (int i = 1; i < w.size(); ++i)
                s.erase(w.substr(i));
        // for(auto  x:s)
        //     cout<<x<<endl;
        int res = 0;
        for (string w : s) 
            res += w.size() + 1;
        return res;
    }
};