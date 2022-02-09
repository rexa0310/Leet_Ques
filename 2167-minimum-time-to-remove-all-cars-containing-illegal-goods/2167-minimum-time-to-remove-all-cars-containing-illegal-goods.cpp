class Solution {
public:
    int minimumTime(string s) {
        int n=s.length();
        int l=0,res=n;
        for(int i=0;i<n;i++)
        {
            l=min(l+(s[i]-'0')*2,i+1);
            res=min(res,l+n-i-1);
        }
        return res;
        }
};