class Solution {
public:
    string removeKdigits(string s, int k) {
        string  res="";
        for(int i=0;i<s.length();i++)
        {
            while(res.length()!=0 && res.back()>s[i] && k>0)
            {
                res.pop_back();
                k--;
            }
            if( res.length()!=0 ||s[i]!='0')
                res.push_back(s[i]);
         //   cout<<res.back();
        }
        while(res.length()!=0 && k--)
         res.pop_back();
        if(res.length()==0)
        return "0";
        else return res;
        
    }
};