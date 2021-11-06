class Solution {
public:
    vector<int> singleNumber(vector<int>& v)
    {
        int x=0;
        for(auto i:v)
            x^=i;
        
        int d=1;
        while(!(d & x))
            d<<=1;
        int f=0;
        for(int i=0;i<v.size();i++)
            if( v[i] & d)
                f^=v[i];
        return {f,x^f};
    }
};
