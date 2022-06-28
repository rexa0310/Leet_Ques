class Solution {
public:
    int countHousePlacements(int n) {
        if(n==1)   
         return 4;
        if(n==2)   
            return 9;
        vector<long long>fib(n+1,0);
        fib[1] = 2;
        fib[2] = 3;
        long mod=1000000007;
        
        for(int i=3;i<=n;i++)
            fib[i] = (fib[i-1]+fib[i-2])%mod;
        
        return (int)(fib[n]*fib[n]%mod);   
    }
};