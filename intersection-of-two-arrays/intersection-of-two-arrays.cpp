class Solution {
public:
    vector<int> intersection(vector<int>& v1, vector<int>& v2)
    {
       unordered_set<int>s;
        for(auto x:v1)
            s.insert(x);
        vector<int>res;
        for(auto x:v2)
        {
            if(s.find(x)!=s.end())
            {
                res.push_back(x);
                s.erase(x);
            }
        }
        return res;
    }
};