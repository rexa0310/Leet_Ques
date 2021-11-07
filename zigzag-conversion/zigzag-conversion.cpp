class Solution {
public:
    string convert(string s, int n)
    {
        if(n<=1)
            return s;
             string res[n];
        bool flag =false;
        int y=0;
        for(int i=0;i<s.length();i++)
        {
            res[y]+=s[i];
          if(y==0)
            flag=true;
            
          if(y==n-1)
            flag=false;
    
          if(flag==true)
            y++;
          else
            y--;
        }
        
        string ans="";
        for(int i=0;i<n;i++)
            ans=ans+(res[i]);
        return ans;
    }
};