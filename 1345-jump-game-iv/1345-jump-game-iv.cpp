class Solution {
public:
    int minJumps(vector<int>& v) {
        int n=v.size();
        vector<int>vis(n+1,0);
        map<int,vector<int>>m;
        m.clear();
        
        for(int i=0;i<n;i++)
        {
            m[v[i]].push_back(i);
        }
        
        queue<int>q;
        int ans=0;
        q.push(0);
        while(!q.empty())
        {
       
            int l=q.size();
             for(int i=0;i<l;i++)
             {
                auto x = q.front();
                 if(x==n-1)
                     return ans;
                 vis[x]=1;
                 q.pop();
                 if(x-1>=0 && !vis[x-1])
                     q.push(x-1);
                 
                 if(x+1<n && !vis[x+1])
                     q.push(x+1);
                 
                 for(auto it: m[v[x]])
                 {
                     if(!vis[it] )
                       q.push(it);
                 }
                 m.erase(v[x]);
            }
           // cout<<q.size()<<" "<<ans<<endl;
          ans++;
            
        }
        
        return ans;
             }
        
};