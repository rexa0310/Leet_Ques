class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s)
    {
    vector<vector<string>> res;
        set<string>st(p.begin(),p.end());
                   
          for(int i=0;i<s.size();i++)
            {
                set<string>temp;
              for(auto it:st)
              {
                  if(it[i]==s[i])
                      temp.insert(it);
              }
                int n;
               if(3>temp.size())
                   n=temp.size();
              else n=3;
              int c=0;
                vector<string>t;
                set<string>::iterator j;
                for(j=temp.begin();j!=temp.end() && c<n;j++)
                {
                    t.push_back(*j);
                    c++;
                }
                res.push_back(t);
                st=temp;
            }
                      return res;
    }
};