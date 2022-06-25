class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int k) {
      int n=v.size(),c=1;
        
        vector<int>pre(n,0),ans;
        pre[0]=1;
        
        for(int i=1;i<n;i++)
        {
            if(v[i]<=v[i-1])
                c++;
            else
                c=1;
             pre[i]=c;
        }
        
      c=1;
        for(int i=n-2;i>=0;i--){
            if(v[i]<=v[i+1])
                c++;
            else
                c=1;
            
           //cout<<c<<" " <<i<<" "<<pre[i]<<endl;
            if(pre[i]-1>=k && c-1>=k)
                ans.push_back(i);
           
        }
        if(k==0)
            ans.push_back(n-1);
    
        return ans;   
    }
};