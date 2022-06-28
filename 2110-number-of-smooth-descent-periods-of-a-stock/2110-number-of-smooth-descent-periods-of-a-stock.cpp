#define ll long long 
class Solution {
public:
    ll getDescentPeriods(vector<int>& v) 
    {
        ll n = v.size();
      
        ll ans = 1,c=1;
        for(ll i=1; i<n; i++)
        {
            if(v[i-1]-v[i]==1)
                c++;
            else
                c=1;;
            
            ans+=c;
        }
        return ans;
    }
};