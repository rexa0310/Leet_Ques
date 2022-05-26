class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& v) {
       vector<pair<int, int>> p;
        for (int i = 0; i < v.size(); ++i)
            for (auto n: v[i]) 
                p.push_back({n, i});
        
        sort(p.begin(), p.end());

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int j = 0; j < p.size(); ++j) 
        {
            if (! mp[p[j].second]++)
                ++k;
            if (k == v.size()) 
            { 
                while (mp[p[i].second] > 1) --mp[p[i++].second]; 
                if (ans.empty() || ans[1] - ans[0] > p[j].first - p[i].first) 
                {
                    ans = vector<int>{p[i].first, p[j].first};
                }
            }
        }

        return ans;  
    }
};