class Solution {
public:
    int rotatedDigits(int n) {
        int c=0;
        
        for(int i=1;i<=n;i++)
        { 
            int flag=0;
            string s=to_string(i);
            for(auto i:s)
            {
                if(i=='2' || i=='5'|| i=='6'|| i=='9')
                    flag=1; 
                else if(i=='0' || i=='1'|| i=='8')
                    continue;   
                else
                {
                    flag=0; 
                    break;
                } 
            }
           if(flag)
               c++;
        }
        
        return c;
    }
};