class Solution {
public:
    bool solve(vector<int>&v,int x,vector<int>&vis,int k,int idx,int cur)
    {
        if(idx>=v.size())
            return false;
        
        if(k==1)
            return true;
        
        if(cur>x)
            return false;
        if(cur==x)
            return solve(v,x,vis,k-1,0,0);
        
        for(int i=idx;i<v.size();i++)
        {
            if(cur+v[i]>x || vis[i]) 
                continue;
            if(vis[i]==0)
            {
                vis[i]=1;
                if(solve(v,x,vis,k,i+1,cur+v[i]))
                    return true;
                vis[i]=0;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& v) {
        int n=v.size();
        int s=0;
        for(auto x:v)
            s+=x;
        
        if(s%4)
            return false;
        vector<int>vis(n,0);
        int x=s/4;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
       return  solve(v,x,vis,4,0,0);
      //  return ans;
        
    }
};