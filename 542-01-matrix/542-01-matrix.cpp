class Solution {
    private:
        bool isvalid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
    
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n=mat.size();
        int m=mat[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>d(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    d[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            
            for(auto i:dir)
            {
                int a=x+i[0];
                int b=y+i[1];
                if(isvalid(a,b,n,m) && d[a][b]==-1)
                {
                    d[a][b]=d[x][y]+1;
                    q.push({a,b});
                }
            }
        }
        return d;
    }
};