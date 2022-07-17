class Solution {
public:
   void dfs(vector<vector<int>> &g,vector<bool> &visited,int &c,int &i)
    {
        visited[i]=true;
        c++;
        for(int j=0;j<g[i].size();j++)
        {
            if(!visited[g[i][j]])
             dfs(g,visited,c,g[i][j]);   
        }
    }
    int maximumDetonation(vector<vector<int>>& v) {

        int n=v.size();
        vector<vector<int> > g(n);
        for(int i=0;i<n;i++)
        {
            long long x1,y1,r1;
            x1=v[i][0];
            y1=v[i][1];
            r1=v[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     long long x2,y2,r2;
                     x2=abs(x1-v[j][0]);
                     y2=abs(y1-v[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)
                        g[i].push_back(j);
                    
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int c=0;
            vector<bool> visited(n,false);
            dfs(g,visited,c,i);
            ans=max(ans,c);
        }
        return ans;
        
    }
};