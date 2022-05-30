class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int c=0,p=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
           c+=min(v[i],v[i+1]);
            v[i+1]=max(v[i],v[i+1]);
            }
        }
        return c;
        
    }
};