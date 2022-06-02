class Solution {
public:
    bool carPooling(vector<vector<int>>& v, int k) {
       
         int n=v.size();
         map<int,int>m;
        for(int i=0;i<n;i++)
        {
            int x=v[i][0];
            int y=v[i][1];
            int z=v[i][2];
            m[y]+=x;
            m[z]-=x;
        }
        for(auto x:m){
            cout<<x.second<<endl;
            
               if ((k -= x.second) < 0)
                return false;
         }
        return true;
    }
};