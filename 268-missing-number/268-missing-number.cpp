class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n=v.size();
        int x=0;
        for(int i=0;i<=n;i++)
            x^=i;
        for(auto i:v)
            x^=i;
        return x;
    }
};