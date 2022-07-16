class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& v) {
         int m = v.size(), n = v[0].size();
        int ans = 0;
        vector<int> v1(n, 0);
		
		
        for(int i = 0; i < m; ++i)
        {	
            for(int j = 0; j < n; ++j)
            {
                if(v[i][j] == 0)
                    v1[j] = 0;
                else 
                    v1[j] += 1;
            }
			
			
            vector<int> temp = v1;
            sort(temp.begin(), temp.end());
			
			
            for(int j = 0; j < n; ++j){
                ans = max(ans, temp[j] * (n - j));
            }
        }
        return ans;
    }
};