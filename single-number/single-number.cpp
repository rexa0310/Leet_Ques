class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo=0;
        for(auto x:nums)
            xo=xo^x;
        return xo;
    }
};