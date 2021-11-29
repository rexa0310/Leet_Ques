class Solution {
public:
     string find(string s, map<string, string>& p)
     {
        return p[s] == s ? s : find(p[s], p);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& v) {
        map<string,string>malik;
     map<string,string>papa;
     map<string,set<string>>family;
     for(int i=0;i<v.size();i++)
     {
         for(int j=1;j<v[i].size();j++)
         {
             papa[v[i][j]]=v[i][j];
             malik[v[i][j]]=v[i][0];
         }
     }

     for(int i=0;i<v.size();i++)
     {
         string x=find(v[i][1],papa);
         for(int j=2;j<v[i].size();j++)
         papa[find(v[i][j],papa)]=x;
     }

     for(int i=0;i<v.size();i++)
     for(int j=1;j<v[i].size();j++)
     family[find(v[i][j],papa)].insert(v[i][j]);

     vector<vector<string>>res;
     for(auto x: family)
     {
         vector<string>temp(x.second.begin(),x.second.end());
         temp.insert(temp.begin(),malik[x.first]);
         res.push_back(temp);
     }
     return res;
}
    
};