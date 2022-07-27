class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& x) {
        vector<vector<int>>res;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i][1]<x[0])
                res.push_back(v[i]);
            
            else if(v[i][0]>x[1])
            {
                res.push_back(x);
                x=v[i];
            }
            else
            {
                x[0]=min(v[i][0],x[0]);
                x[1]=max(v[i][1],x[1]);
                
            }
            cout<<x[0]<<" "<<x[1]<<endl;
        }
        res.push_back(x);
        return res;
    }
};