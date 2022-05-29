class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
        vector<int>in(100006,0);
        set<int>s;
        for(int i=0;i<v.size();i++)
            {
                s.insert(v[i][0]);
                s.insert(v[i][1]);
                in[v[i][1]]++;
            }
            vector<int>a1,a2;
            for(auto x:s)
            {
                if(in[x]==0)
                    a1.push_back(x);
                if(in[x]==1)
                    a2.push_back(x);
            }
            vector<vector<int>>ans;
            ans.push_back(a1);
            ans.push_back(a2);
            return ans;
    }
};