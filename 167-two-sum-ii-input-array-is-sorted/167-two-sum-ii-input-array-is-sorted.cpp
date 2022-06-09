class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
         int l = 0;
    int r = v.size() -1;
   
    while(l < r)
    {
        if(v[l] + v[r] == k)
            return {l+1,r+1};
        
        else if(v[l] + v[r] > k)
            r--;
        
        else
            l++;
        
    }
	return {};
    }
};