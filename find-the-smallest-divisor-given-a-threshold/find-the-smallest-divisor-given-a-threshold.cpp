class Solution {
public:
    int smallestDivisor(vector<int>& nums, int y) {
        long h=0;
        for(auto  x:nums)
            h+=x;
        long l=1;
        long mid,s;
        while(l<h)
        {
            mid=l+(h-l)/2;
            s=0;
            for(auto x:nums)
                s+=(x+mid-1)/mid;
            if(s>y)
                l=mid+1;
            else h=mid;
        }
        return l;
    }
};