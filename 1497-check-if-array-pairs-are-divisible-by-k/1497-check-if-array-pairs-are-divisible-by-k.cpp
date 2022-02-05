class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
       if(v.size()&1) 
           return false;
        unordered_map<int,int>m;
        for(auto x:v) 
            m[(x%k + k)%k]++;   
        for(auto x:v)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                         
            { 
                if(m[rem]%2!=0) 
                    return false;            
            }         
            else if(m[rem] != m[k - rem]) 
                return false;  
        }
        return true;
    }
};