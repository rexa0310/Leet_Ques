class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int k) {
         sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                int l = j + 1, r = n - 1;
                int dif = k - v[i] - v[j];
                while (l < r) 
                {
                    if (v[l] + v[r] == dif)
                    {
                        ans.push_back({v[i], v[j], v[l], v[r]});
                        ++l; 
                        --r;
                        while (l < r && v[l-1] == v[l])
                            ++l; 
                    } 
                    else if (v[l] + v[r] > dif)
                        --r;
                    else 
                        ++l;
                    
                }
               while (j+1 < n && v[j] == v[j+1])
                  ++j; 
            }
        while (i+1 < n && v[i] == v[i+1])
                ++i; 
        }
        return ans;
    }
};