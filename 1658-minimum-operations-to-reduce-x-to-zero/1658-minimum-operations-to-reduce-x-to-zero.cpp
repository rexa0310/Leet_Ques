class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), j = 0, s = 0, m = -1;
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum < x)
            return -1;
        for(int i = 0; i < n; i++)
        {
            s += nums[i];
            while (s > sum - x)
                s -= nums[j++];
            if(s == sum - x) 
                m = max(m, i - j + 1);
        }
        if(m == -1)
            return -1;
        return n - m;
    }
};