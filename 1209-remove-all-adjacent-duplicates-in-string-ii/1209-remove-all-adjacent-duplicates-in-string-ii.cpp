class Solution {
public:
    string removeDuplicates(string s, int k) {
        int j=0;
        vector<int>c(s.length(),0);
        for(int i=0;i<s.length();i++)
        {
            s[j]=s[i];
            if(j>0 && s[j]==s[j-1])
                c[j]=c[j-1]+1;
            else 
                c[j]=1;
        
            if(c[j]==k)
                j-=k;
            
            j++;
        }
        return s.substr(0,j);
    }
};