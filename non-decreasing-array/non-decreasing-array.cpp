class Solution {
public:
    bool checkPossibility(vector<int>& v) {
        int c=0;
        for(int i=1;i<v.size() ;i++)
        {
            if(v[i-1]>v[i])
            { 
                c++;
            if(i-2<0 || v[i-2] <= v[i])
               v[i-1] = v[i]; 
                else
                v[i] =v[i-1]; 
            }
            cout<<c<<" "<<v[i]<<endl;
        }
        if(c>1)
            return false;
        return true;
    }
};