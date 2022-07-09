class Solution {
public:
    string pushDominoes(string s) {
          int n=s.size();
        vector<int> l(n), r(n);
        
        int x=-1;
        for(int i=0;i<s.size();i++)
        {
            if(x==-1)
                r[i]=999999;
            else
                r[i]=i-x;
            if(s[i]=='R')
                x=i;
            if(s[i]=='L') 
                x=-1;
        }
        
         x=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(x==-1) 
                l[i]=999999;
            else 
                l[i]=x-i;
            if(s[i]=='L') 
                x=i;
            if(s[i]=='R') 
                x=-1;
        }
        
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                if(l[i]<r[i])
                    res+='L';
                else if(l[i]>r[i]) 
                    res+='R';
                else 
                    res+='.';
            }
            else
                res+=s[i];
        }
        return res;
    }
};