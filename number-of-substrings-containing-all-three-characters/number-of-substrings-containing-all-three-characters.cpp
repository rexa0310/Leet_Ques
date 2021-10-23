class Solution {
public:
    int numberOfSubstrings(string s) 
    {
         vector<int>v(3,0);
       
        int res=0,i=0;
        for(auto c:s)
        {
            v[c-'a']++;
            while(v[0] && v[1] && v[2])
                 --v[s[i]-'a'],i++;
            res+=i;
        }
        return res;
    }
};