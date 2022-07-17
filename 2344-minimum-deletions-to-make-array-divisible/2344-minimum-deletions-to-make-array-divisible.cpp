class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
         int t = b[0];
        for(auto x: b)
            t = __gcd(t,x);
        
        
        

        int c=0;
        sort(a.begin(),a.end());
        for(auto x:a)
        {
            if(t%x)
            {
                c++;
            }
            else break;
        }
        if(c==a.size())
            return -1;
        
        return c;
    }
};