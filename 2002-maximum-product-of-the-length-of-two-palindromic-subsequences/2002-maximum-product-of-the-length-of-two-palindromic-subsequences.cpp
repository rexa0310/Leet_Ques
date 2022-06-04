class Solution {
public:
   long long ans = 0;
    
    bool isPal(string &s)
    {
        int start=0, end = s.length()-1;
        while(start < end)
        {
            if(s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
    
    void recur(string &s,int idx,string &s1,string &s2)
    {
        if(idx == s.size())
        {
            if(isPal(s1) and isPal(s2))
            {
                long long val =(int) s1.length() * s2.length();
                ans = max(ans , val);
            }
            return;
        }
        
        s1.push_back(s[idx]);
        recur(s,idx+1,s1, s2);
        s1.pop_back();
        
        s2.push_back(s[idx]);
        recur(s,idx+1,s1,s2);
        s2.pop_back();
        
        recur(s,idx+1,s1,s2);
    }
	
	int maxProduct(string s) {
        string s1="", s2 = "";
        recur(s,0,s1,s2);
        return ans;
    }
};