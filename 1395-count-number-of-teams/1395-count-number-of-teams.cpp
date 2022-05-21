class Solution {
public:
    int numTeams(vector<int>& v) 
    {
        int c = 0,n = v.size();
        for (int j = 0; j < n; j++)
        {
            
        int ls = 0, rg = 0;
        int ll = 0, rs = 0;
            
        for (int k = j + 1; k < n; k++)
        {
        if (v[j] < v[k]) 
            rg++;
        else if (v[j] > v[k]) 
            rs++;
         }
        
        for (int i = 0; i < j; i++)
        {
        if (v[i] < v[j]) 
            ls++;
        else if (v[i] > v[j]) 
            ll++;
        }
            
            
        c += ls * rg + ll * rs;
        }
     return c;
    }
};