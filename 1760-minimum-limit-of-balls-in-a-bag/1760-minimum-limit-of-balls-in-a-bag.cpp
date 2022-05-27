class Solution {
public:
    int minimumSize(vector<int>& v, int k) 
    {
    int l = 1, h = 1e9;
        while (l < h) 
        {
            int m = (l + h) / 2, c = 0;
            
            for (int x : v)
                c += (x - 1) / m;
            
            if (c > k)
                l = m + 1;
            else
                h = m;
        }
        return l;    
    }
};