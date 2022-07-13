class Solution {
public:
    int numEnclaves(vector<vector<int>>& v) {
     int res=0; 
   queue<pair<int, int>> q;
  for (auto i = 0; i < v.size(); ++i)
    for (auto j = 0; j < v[0].size(); ++j) 
    {
      res += v[i][j];
      if (i*j==0|| i==v.size()-1|| j == v[i].size() - 1)
          q.push({ i, j });
    }
        
    while (!q.empty())
    {
       auto x = q.front().first, y = q.front().second; 
        q.pop();
       if (x<0|| y<0|| x==v.size()|| y==v[x].size()|| v[x][y]!=1)
        continue;
        v[x][y] = 0;
        --res;
        q.push({ x + 1, y });
        q.push({ x - 1, y });
        q.push({ x, y + 1 });
        q.push({ x, y - 1 });
  }
        
  return res;
} 
    
};