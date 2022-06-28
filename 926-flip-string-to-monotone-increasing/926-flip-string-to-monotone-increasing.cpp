class Solution {
public:
    int minFlipsMonoIncr(string s) {
         int n = s.size(),ans = INT_MAX;
        vector<int> pre(n,0), suf(n,0);
    
        
        for(int i=0; i<n; i++)
        {
            if(i == 0)
            {
                if(s[i] == '1')
                    pre[i]=1;
                continue;
            }
            if(s[i] == '1')
                pre[i] = pre[i-1]+1;
            else
                pre[i] = pre[i-1];
            
        }
     for(int i=n-1; i>=0; i--)
        {
            if(i == n-1)
            {
                if(s[i] == '0')
                    suf[i]=1;
                continue;
            }
            if(s[i] == '0')
                suf[i] = suf[i+1]+1;
            else
                suf[i] = suf[i+1];
        }
        

       for(int i=0;i<n;i++)
        {
            if(i == 0)
                ans = min(suf[i], ans);
            else if(i == n-1)
                ans = min(ans, pre[i]);
            else
            {
                ans = min(pre[i-1]+suf[i],ans);
                ans = min(pre[i]+suf[i+1], ans);
            }
        }
        return ans;
    
    }
};