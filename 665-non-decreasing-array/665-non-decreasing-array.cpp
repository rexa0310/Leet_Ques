class Solution {
public:
    bool checkPossibility(vector<int>& v) {
        int c=0;
        for(int i=1;i<v.size() && c<=1 ;i++)
        {
            if(v[i-1]>v[i])
            { 
                c++;
            if(i-2<0 || v[i-2] <= v[i])
               v[i-1] = v[i]; 
                else
                v[i] =v[i-1]; 
            }
           
        }
        return c<=1; 
    }
};