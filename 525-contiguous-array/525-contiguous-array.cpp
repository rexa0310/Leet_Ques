class Solution {
public:
    int findMaxLength(vector<int>& v)
    {
        int s=0,maxi=0;
        unordered_map<int,int>m{{0,-1}};
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
                s--;
            else
                s++;
            if(m.find(s)!=m.end())
                maxi=max(maxi,i-m[s]);
            else
                m[s]=i;
        }
        return maxi;
    }
};