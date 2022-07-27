class Solution {
public:
    int div(int x)
    {
        int c=0,s=0;
        for(int i=1;i<=sqrt(x);i++)
        {
            if(x%i==0)
            {
                if(i!=x/i)
                {
                      c+=2;
                     s+=x/i;
                }
                else
                    c+=1;
                
                s+=i;
            }
        }
            if(c==4)
                return s;
            return 0;
        
    }
    int sumFourDivisors(vector<int>& v) {
      int s=0;
        for(int i=0;i<v.size();i++)
        {
            s+=div(v[i]);
        }
        return s;
    }
};