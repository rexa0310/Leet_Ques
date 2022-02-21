class Solution 
{
public:
    vector<vector<int>>res;
    vector<int>cnt;
    void solve(vector<int>v,int t,int idx)
    {
        if(t==0)
        {
            res.push_back(cnt);
            return;
        }
        if(idx==v.size() || t<0)
            return ;
        cnt.push_back(v[idx]);
        solve(v,t-v[idx],idx);
        cnt.pop_back();
        solve(v,t,idx+1);       
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t)
    {
        solve(v,t,0);
        return res;   
    }
};