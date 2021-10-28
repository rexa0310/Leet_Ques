class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) 
    {
        vector<vector<int>>res;
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++)
        {
            if(i>0 && v[i]==v[i-1])
                continue;
            int l=i+1,r=v.size()-1;
            while(l<r)
            {
                int s=v[i]+v[l]+v[r];
                if(s>0)
                    r--;
                else if(s<0)
                    l++;
                else
                {
                    res.push_back(vector<int> {v[i],v[l],v[r]});
                    while(l<r && v[l]==v[l+1])
                        l++;
                    while( l<r && v[r]==v[r-1])
                        r--;
                    
                    l++;
                    r--;
                }
            }
            
        }
        return res;
        
    }
};