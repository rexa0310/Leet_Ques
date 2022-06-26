class Solution {
public:
    int maximumsSplicedArray(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        
        int s1 = accumulate(v1.begin(),v1.end(),0);
        int s2 = accumulate(v2.begin(),v2.end(),0);
        
        int d1 = 0, d2 = 0, ans = 0;
         
        for(int i=0; i<n; i++)
        {
            d1 += v2[i]-v1[i];
            d2 += v1[i]-v2[i];
            
            ans = max({ans , s1+d1 , s2+d2});
            
            if(d1<0)
                d1 = 0;
            if(d2<0)
                d2 = 0;
        }
        
        return ans; 
    }
};