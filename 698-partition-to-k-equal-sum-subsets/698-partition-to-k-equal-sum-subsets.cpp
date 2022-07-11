class Solution {
public:
      bool solve(vector<int> &v,int k,int x,vector<int> &v1,int cur,int idx)
    {
        if(idx>=v.size())
            return false;
          
        if(k==1) 
            return true;
          
        if(cur>x) 
            return false;
          
        if(cur==x)
        {
             return solve(v,k-1,x,v1,0,0);
        }
        for(int i=idx;i<v.size();i++)
        {
            if(cur+v[i]>x || v1[i]) 
                continue;
            if(v1[i]==0)
            {
                v1[i]=1;
                if(solve(v,k,x,v1,cur+v[i],i+1))
                    return true;
                v1[i]=0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& v, int k)
    {
        int n=v.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=v[i];
        
        if(sum%k) 
            return false;
        
        int x=sum/k;
        vector<int> v1(n,0);
        sort(v.begin(),v.end(),greater<int>());
        
        return solve(v,k,x,v1,0,0);
    }
};