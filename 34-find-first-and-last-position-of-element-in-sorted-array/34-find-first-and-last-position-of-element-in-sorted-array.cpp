class Solution {
public:
    
   int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r)
    {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}
    
    vector<int> searchRange(vector<int>& nums, int target) {
         int x = lower_bound(nums, target);
         int y = lower_bound(nums, target+1)-1;
         if (x < nums.size() && nums[x] == target)
        return {x, y};
    else
        return {-1, -1};
  }
    
};