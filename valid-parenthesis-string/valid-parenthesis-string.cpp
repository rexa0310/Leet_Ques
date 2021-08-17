class Solution {
public:
    bool checkValidString(string s) {
        int mi=0,ma=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                ma++,mi++;
            if(s[i]==')')
                ma--,mi=max(mi-1,0);
            if(s[i]=='*')
                ma++,mi=max(mi-1,0);
            
            if(ma<0)
                return false;
        }
        if(mi==0)
            return true;
        return false;
    }
};