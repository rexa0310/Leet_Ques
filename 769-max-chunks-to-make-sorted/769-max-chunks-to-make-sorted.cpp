class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
         int ans = 0,m=0;
        for (int i = 0; i < v.size(); i++) 
        {
            m = max(v[i], m);
            if (m == i) 
                ans++;
        }
        return ans;
    }
};