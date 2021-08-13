class Solution {
public:
    bool canReorderDoubled(vector<int>& v) {
        sort(v.begin(),v.end());
        unordered_map<int,int>m;
         for( auto x:v)
             m[x]++;
        int n=v.size();
        
        for(auto x:v)
        {
           if(m[x]==0)
               continue;
            if(x<0 && m[x/2-x%2]==0)
                return false;
             int y=0;
            
         if( x>0)
             y=x*2;
            else 
                y=x/2;
            m[x]--;
            m[y]--;
            
        }
        
        for(auto x: m)
        if(x.second!=0)
            return false ;
        return true;
    }
};