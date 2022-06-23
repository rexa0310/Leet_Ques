class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& v, vector<int>& t) {
        vector<vector<int>> adj(n);
        vector<int> in(n),time(n,0);
		int ans=0;
          queue<pair<int,int>> q;
        for(auto &r:v) 
        {        
            adj[r[0]-1].push_back(r[1]-1);
			in[r[1]-1]++;
		}
		
        for(int i=0;i<n;i++)            
            if(!in[i])
                q.push({i,0});

        while(!q.empty()) 
        {
            auto x=q.front();    
            q.pop();
			
            int c=x.second + t[x.first];
            time[x.first]=c;
           // cout<<c<<" ";
            ans=max(ans,time[x.first]);
			for(int &y:adj[x.first])
            {	
                time[y]=max(time[y],c);
				in[y]--;
                ans=max(ans,time[y]);
                if(in[y]==0)      
                    q.push({y,time[y]});
            }
        }
	
        return ans;
    }
};