class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v)
    {
       int n=v.size();
        int  j=0,m=0;
        unordered_set<int>s;
        int s1=0;
        for(int i=0;i<n;i++)
        {
         while(s.count(v[i]))
         {
             s.erase(v[j]);
             s1-=v[j++];
            
         }
            s.insert(v[i]);
            s1+=v[i];
            m=max(m,s1);
        }
        return m;
    }
};
 