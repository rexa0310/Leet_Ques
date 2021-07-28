class Solution {
public:
    void nextPermutation(vector<int>& v)
    {
      int i,n=v.size();
        for( i=n-2;i>=0;i--)
            if(v[i]<v[i+1])
             break;
        
         
        if(i<0)
            reverse(v.begin(),v.end());
        else
        {
            int y;     
           for(y=n-1;y>i;y--)
            if(v[y]>v[i])
            {
                break;
            }
              swap(v[y],v[i]);
             reverse(v.begin()+i+1,v.end());
        }
    }
};