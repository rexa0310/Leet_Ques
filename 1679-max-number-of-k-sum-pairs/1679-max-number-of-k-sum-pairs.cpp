class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        map<int,int>m;
        for(auto x:v)
            m[x]++;
      int c=0;  
        for(auto x:v)
        {
            if(k-x==x && m[k-x]>1)
            {
                c++;
                m[x]--;
                m[k-x]--;
            }
            else if(k-x!=x && m[k-x] && m[x])
            {
                c++;
                  m[x]--;
                m[k-x]--;
            }
                
        }
        // for(auto x:m)
        //     cout<<x.first<<" "<<x.second<<endl;
        return c;
    }
};