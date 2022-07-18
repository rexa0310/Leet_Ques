class Solution {
public:
     bool check(string s1,string s2){
        string a,b;
        for(auto it : s1) if(it!='_') a+=it;
        for(auto it : s2) if(it!='_') b+=it;
        return a==b;
    }
    bool canChange(string s, string t) {
        int n = s.length();
        if(!check(s,t))
            return false;
        vector<int> l1,l2,r1,r2;
        
        for(int i=0 ; i<n ; i++)
        {
            if(s[i]=='L') 
                l1.push_back(i);
            if(s[i]=='R') 
                r1.push_back(i);
            if(t[i]=='L') 
                l2.push_back(i);
            if(t[i]=='R') 
                r2.push_back(i);
        }
        
        for(int i=0 ; i<l1.size() ; i++)
            if(l1[i]<l2[i]) 
                return false;
        for(int i=0 ; i<r1.size() ; i++) 
            if(r1[i]>r2[i])
                return false;
        
        return true;
        
    }
};