class Solution
{
public:
    int findKthLargest(vector<int>& v, int k) 
    {
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        return v[k-1];
    }
};