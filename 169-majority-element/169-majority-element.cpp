class Solution {
public:
    int majorityElement(vector<int>& v) {
        int c=0,x=v[0];
        for(int i=0;i<v.size();i++)
        {
            // if(c==0)
            //     x=v[i];
            if(x==v[i])
                c++;
            else
                c--;
            if(c==0)
                x=v[i],c=1;
           
        }
        return x;
    }
};