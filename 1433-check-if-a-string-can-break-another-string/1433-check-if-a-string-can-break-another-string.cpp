class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int c=0,c1=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]>=s2[i])
                c++;
            if(s2[i]>=s1[i])
                c1++;
        }
    
        if(c==s1.length()||c1==s1.length())
        return true;
        return false;
    }
};