class Solution {
public:
    bool isBipartite(vector<vector<int>>& v) {
        
        int n=v.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i]=0;
                while(!q.empty())
                {
                    int l=q.size();
                    while(l--)
                    {
                        int x=q.front();
                        q.pop();
                        for(auto it:v[x])
                        {
                            if(color[it]==-1)
                            {
                                q.push(it);
                                color[it]=1-color[x];
                            }
                            else
                            {
                                if(color[x]==color[it])
                                    return false;
                            }

                        }
                   }

                }
            }
        }
        return true;
    }
};