class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
     vector<int> x = v[0];
        for(int i = 1; i < v.size(); ++i)
        {
            vector<int> temp;
            for(int j = 0; j < v[i].size(); ++j) 
            {
                for(auto n : x)
                    temp.push_back(v[i][j] + n);
                
            }
            
            sort(temp.begin(), temp.end());
            x.resize(min(k, int(temp.size())));
            
            for(int it = 0; it <min(k, int(temp.size())) ;++it) 
                x[it] = temp[it];
        }
        return x[k-1];   
    }
};