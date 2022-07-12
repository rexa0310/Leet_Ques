class Solution {
public:
    int numOfWays(int n) {
         long c2 = 6, c3 = 6;
        long mod = 1e9+7;
        for (int i=0; i<n-1; i++) 
        {
            auto tmp = c3;
            c3 = (2*c2 + 2*c3) % mod;
            c2 = (3*c2 + 2*tmp) % mod;
        }
        return (c2+c3)%mod; 
    }
};