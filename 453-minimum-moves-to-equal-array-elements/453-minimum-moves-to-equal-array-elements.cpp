class Solution {
public:
    int minMoves(vector<int>& v)
    {
      int m=INT_MAX;
        for(auto x:v)
            m=min(m,x);
        int s=0;
        for(auto x:v)
            s+=(x-m);
        return s;
    }
};