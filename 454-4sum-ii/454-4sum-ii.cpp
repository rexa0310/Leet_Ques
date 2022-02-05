class Solution {
public:
       int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4)
    {
      int c=0;
       unordered_map<int,int>m;
        for(int i=0;i<n1.size();i++)
            for(int j=0;j<n2.size();j++)
                m[n1[i]+n2[j]]++;
          for(int i=0;i<n3.size();i++)
            for(int j=0;j<n4.size();j++)
            {
                auto it=m.find(-n3[i]-n4[j]);
                  if(it!=m.end())
                      c+=it->second;
           }
        return c;
       }
};