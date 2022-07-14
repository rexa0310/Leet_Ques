class Solution {
public:
    long long mod=1e9+7;
    
    int sumSubarrayMins(vector<int>& v) {
        int n=v.size();
        stack<int>st;
        vector<int>l(n,-1),r(n,-1);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && v[st.top()]>v[i])
                st.pop();
            
            if(!st.empty())
                l[i]=i-st.top();
            else
                l[i]=i+1;
            
            st.push(i);
        }
       
         while(st.size()) 
             st.pop();
        
        
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && v[i] <= v[st.top()]) 
                st.pop();
            
            if(st.size()) 
                r[i] = st.top() - i;
            else 
                r[i] = n - i;
            
            st.push(i);
        }
        
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long p = (l[i]*r[i])%mod;
            p = (p*v[i])%mod;
            res = (res + p)%mod;
        }
        
        return res%mod;
        
    }
};