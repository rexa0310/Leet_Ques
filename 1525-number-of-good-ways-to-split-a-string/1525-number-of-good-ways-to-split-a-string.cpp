class Solution {
public:
    int numSplits(string s) {
      vector<int>l(26,0),r(26,0);
        int lc=0,rc=0,c=0;
    for (auto x : s)
    {
        if(++r[x-'a']==1)
            rc++;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if(++l[s[i] - 'a'] == 1)
            lc++;
        if(--r[s[i] - 'a'] == 0)
            rc--;
         if(lc==rc)
             c++;
    }
    return c;   
    }
};