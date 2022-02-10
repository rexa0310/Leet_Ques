class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
      unordered_map<int,int>m;
        m[0]++;
        int s=0,r=0;
        for(int i=0;i<v.size();i++)
        {
            s+=v[i];
            r+=m[s-k];
            m[s]++;
        }
        return r;   
    }
};