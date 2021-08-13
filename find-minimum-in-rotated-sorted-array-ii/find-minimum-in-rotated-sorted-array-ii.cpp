class Solution {
public:
    int findMin(vector<int>& v) {
         int n=v.size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
             if (v[m] > v[h]) 
                l = m + 1;
            
            else if (v[m] <v[l]) 
            { 
                h = m;
                l++;
            }
            else 
                h--;
        }
        return v[l];
            
    }
};