class Solution {
public:
    int minimumDeletions(string s) {
         vector<int>pref , suff ;
          int b = 0 ;
        for(int i = s.size() - 1 ; i >= 0 ; --i )
        {
            b += s[i] == 'b' ;
            suff.push_back(b) ;
        }
        
        int a = 0 ;
        for(int i = 0 ; i < s.size() ; ++i )
        {
            a += s[i] == 'a' ;
            pref.push_back(a) ;
        }
      
        reverse(begin(suff),end(suff)) ; 
        
        int ans = s.size() ;
        int n=ans;
        for(int i = 0 ; i <n ; ++i )
            ans = min(ans,(int)s.size() - pref[i] - suff[i]) ;
        return ans ;
    }
};