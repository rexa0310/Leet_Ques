class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       if (k <= 1) return 0;
        int n = nums.size(), p = 1, ans = 0, l = 0;
        for (int i = 0; i < n; i++)
        {
            p *= nums[i];
            while (p >= k)
            {
                p/= nums[l];
                l++;
            }
            ans += i - l + 1;
        }
        return ans;
    }
};