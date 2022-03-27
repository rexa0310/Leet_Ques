class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& v1, vector<int>& v2) {
            unordered_set<int> sa(begin(v1), end(v1)), sb(begin(v2), end(v2));
        vector<vector<int>> ans(2);
        for (int n : sa)
        {
            if (sb.count(n) == 0)
                ans[0].push_back(n);
        }
        for (int n : sb)
        {
            if (sa.count(n) == 0) 
                ans[1].push_back(n);
        }
        return ans;
    }
};