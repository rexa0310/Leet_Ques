class Solution {
public:
    int subarraysWithKDistinct(vector<int>& v, int k)
    {
         vector<int> m(v.size() + 1);
        int res=0;
  for(auto i = 0, j = 0, prefix = 0, cnt = 0; i < v.size(); ++i)
  {
    if (m[v[i]]++ == 0) 
        ++cnt;
    if (cnt > k) 
        --m[v[j++]], --cnt, prefix = 0;
    while (m[v[j]] > 1) 
        ++prefix, --m[v[j++]];
    if (cnt == k)
        res += prefix + 1;
  }
  return res; 
    }
};