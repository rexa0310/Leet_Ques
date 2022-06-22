class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& v, int k) {
         int r = v.size() , c = v[0].size();
        
        
        for(int i = 0 ; i < r ; i++)
        {
            for(int j = 1 ; j < c ;j++)
                v[i][j] =  v[i][j] + v[i][j -1];
            
        }
      
        int cnt = 0 , s ;
        unordered_map<int , int> m;
        for(int j1 = 0 ; j1 < c ;j1++)
        {
            for(int j = j1 ; j < c; j++)
            {
                m.clear();
                m[0] = 1;
                s =0;
                for(int i = 0 ; i < r ;i++)
                {
                    int y=0;
                    if(j1>0)
                        y=v[i][j1-1];
                    s += v[i][j] - y;
                    
                    if(m.find(s-k)!=m.end())
                        cnt+=m[s-k];
                    
                    m[s]++;
                }
            }
        }
        return cnt;
    }
};