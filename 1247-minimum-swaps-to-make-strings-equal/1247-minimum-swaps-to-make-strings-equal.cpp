class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1=0,y1=0,x2=0,y2=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(s1[i]=='x')
                    x1++;
                 if(s1[i]=='y')
                     y1++;
                if(s2[i]=='x')
                    x2++;
                 if(s2[i]=='y')
                     y2++;
            }
            
        }
        int c=0;
     //   cout<<x1<<endl;
       
           int a=min(x1/2,y2/2);
           c+=a;
           x1=x1-2*a;
           y2=y2-2*a;
       
       // cout<<x1<<y2<<" "<<c<<endl;
        
           int a1=min(x2/2,y1/2);
           c+=a1;
           x2=x2-2*a1;
           y1=y1-2*a1;
       
        if(x1==y1 && x2==y2 && x1==x2)
        {
            c+=x1*2;
        }
         if(x1!=y1 || x1!=x2)
            return -1;
        return c;
        
        
    }
};