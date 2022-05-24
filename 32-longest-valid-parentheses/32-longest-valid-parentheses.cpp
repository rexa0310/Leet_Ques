class Solution {
public:
    int longestValidParentheses(string s) {
     int x=0,y=0,m=0;
        for(auto i:s)
        {
            if(i=='(')
                x++;
            else
                y++;
            
            if(x==y)
                m=max(m,2*x);
            else if(y>x)
            {
                x=y=0;
            }
        }
      //  cout<<m;
        x=y=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                x++;
            else
                y++;
            
            if(x==y)
                m=max(m,2*x);
            else if(x>y)
                x=y=0;
        }
        return m;
    }
};