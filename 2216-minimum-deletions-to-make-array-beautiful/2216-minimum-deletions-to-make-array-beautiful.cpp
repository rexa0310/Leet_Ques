class Solution {
public:
    int minDeletion(vector<int>& nums) {
         int c = 0;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if ((i + c) % 2 == 0 && nums[i] == nums[i + 1])
                        c++;
            }
        if((nums.size()-c)%2==1)
        c++;
        return c;
    }
};