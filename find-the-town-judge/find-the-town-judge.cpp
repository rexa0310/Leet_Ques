class Solution {
public:
    int findJudge(int n, vector<vector<int>>& x) {
        if(n==1)
         return 1;
        
        vector<int>v(n+1,0);
        for(int i=0;i<x.size();i++)
        {
            v[x[i][1]]++;
             v[x[i][0]]--;
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]==n-1)
                return i;
        }
        return -1;
    }
};