class Solution {
public:
    int search(vector<int>& v, int target) {
        int l=0,h=v.size()-1;
        if(l==h && v[l]==target)
            return 0;
        while(l<=h )
        {
            int mid=l+(h-l)/2;
            if(v[mid]==target)
                return mid;
            else if(v[mid]>target)
                h=mid-1;
            else
                l=mid+1;
        }
        
        return -1;
    }
};