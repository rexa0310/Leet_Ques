class Solution {
public:
    int numSub(string s) {
        int n=s.size();
        int s1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
              long long c=0;
                while(s[i]=='1')
                {
                    c++;
                    i++;
                }
                c=((c*(c+1))%1000000007)/2; 
                s1=(s1+c)%1000000007;
            
                
            }
        }
        return s1%1000000007;
    }
};