class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int m1=INT_MAX,m2=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<=m1)
                m1=v[i];
            else if(v[i]<=m2)
                m2=v[i];
            else 
                return true;
        }
        return false;
    }
};