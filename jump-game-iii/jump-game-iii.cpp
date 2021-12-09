class Solution 
{
public:
    bool canReach(vector<int>& v, int s) 
    {
        if(s>=0 && s<v.size() && v[s]>=0 && v[s]<v.size())
        {
            int x=v[s];
            if(v[s]==0)
                return true;
            v[s]=-1;
            return (canReach(v,s+x) || canReach(v,s-x));
            
        }
                    return false;
        }
};