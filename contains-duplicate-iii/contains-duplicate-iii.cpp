class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& v, int k, int t) {
        
            int n=v.size();
            if(n==0)
                   return 0;
           set<long>s;
            for(int i=0;i<n;i++)
            {
                    if(i>k)
                         s.erase(v[i-1-k]);
                    auto x=s.lower_bound(long(v[i])-long(t));
                    if(x!=s.end() && *x-long(v[i])<=long(t))
                            return true;
                    
                    s.insert(v[i]);
            }
            return false;
    }
};
     