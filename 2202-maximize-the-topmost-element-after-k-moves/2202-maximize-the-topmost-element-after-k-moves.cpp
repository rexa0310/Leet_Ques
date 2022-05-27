class Solution {
public:
    int maximumTop(vector<int>& v, int k) {
        if(k==0)
        {
            if(v.size()>=1)
                return v[0];
            return -1;
                
        }
        if(k==1)
        {
            if(v.size()>1)
                return v[1];
            return -1;
        }
        if(v.size()==1)
        {
         if(k%2==0)
             return v[0];
        return -1;
        }
        
        int m=-1,n=v.size();
        for(int i=0;i< min(k-1,n);i++)
            m=max(m,v[i]);
        
         if(k<v.size())
             m=max(m,v[k]);
        return m;
    }
};