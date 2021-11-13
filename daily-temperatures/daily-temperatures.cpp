class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    
    {
          vector<int> res(t.size(),0);
        stack <int> s;       
        for(int i=t.size()-1;i>=0;i--) 
        {
           while(!s.empty())
           {
               if(t[i]<t[s.top()])
               {
                   res[i]=s.top()-i;
                   break;
               }
               else
                   s.pop();
           }
           s.push(i);
        }
        return res;
    }
};
    