class Solution {
public:
    bool isPossibleDivide(vector<int>& v, int k) {
       map<int,int> m;
        for(auto x : v)
            m[x]++;
        
        for(auto [x, y] : m)
        {
            while(m[x])
            {
                for(int i = x; i < x + k; ++i)
                {
                    m[i]--;
                    if(m[i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};