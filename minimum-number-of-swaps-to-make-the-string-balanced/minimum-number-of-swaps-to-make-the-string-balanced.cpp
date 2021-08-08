class Solution {
public:
    int minSwaps(string s) {
        int c=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')
                c++;
            else 
            {
                if(c>0)
                    c--;
                
            }
        }
        if(c%2)
            return c/2 +1;
        else 
            return c/2;
    }
};