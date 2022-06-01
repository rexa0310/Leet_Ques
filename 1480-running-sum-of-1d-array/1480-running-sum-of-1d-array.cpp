class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>s(nums.size(),0);
        s[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            s[i]=s[i-1]+nums[i];
        }
        return s;
    }
};