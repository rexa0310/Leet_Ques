class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(!d.empty() && d.front()==i-k)
                d.pop_front();
            while(!d.empty() && nums[d.back()]<=nums[i])
                d.pop_back();
            d.push_back(i);
            if(i>=k-1)
                ans.push_back(nums[d.front()]);
       
        }
        return ans;
    }
};