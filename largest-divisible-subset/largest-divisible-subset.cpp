class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> result(nums.size());
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int l = 0, r = i;
            while(l < r){
                int a = nums[l], b = nums[r];
                if(a < b) swap(a,b);
                if(a % b == 0 && result[l].size() > result[r].size()){
                    result[r] = result[l];
                }
                l++;
            }
            result[i].push_back(nums[i]);
            if(ans.size() < result[i].size()){
                ans = result[i];
            }
        }
        return ans;
    }
};