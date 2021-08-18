class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
     
        vector<vector<int>>res;
        
        int n=f.size(),m=s.size();
        if(n==0 || m==0)
            return res;
        int i=0,j=0;
        while(i<n && j<m)
        {
            int m=min(f[i][1],s[j][1]);
            int mi=max(f[i][0],s[j][0]);
            if(m>=mi)
                res.push_back({mi,m});
            
            if(f[i][1]<s[j][1])
               i++;
               else
               j++;
                
        }
               return res;
        
    }
};