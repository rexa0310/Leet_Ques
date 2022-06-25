class Solution {
public:
    int carFleet(int t, vector<int>& v, vector<int>& s) {
         map<int, double> m;
        for (int i = 0; i < v.size(); i++)
            m[v[i]] = (double)(t - v[i]) / s[i];
        
        int res = 0; double cur = 0;
     
        
        for(auto x=m.rbegin();x!=m.rend();x++)
        {
            if(x->second>cur)
            {
                cur=x->second;
                res++;
            }
        }
        return res;
    }
};