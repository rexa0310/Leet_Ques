class Solution {
public:
    bool canReach(string s, int mini, int maxi)
    {
       int n=s.length();
        if (s[n - 1] != '0') 
           return false;
       cout<<n; 
        set<int>q;
        q.insert(0);

        while (!q.empty())
        {
            auto it = q.begin();
            int cur=*it;
            q.erase(cur);

            int mi =min(n - 1, cur + maxi);
            for (int i =cur+mini; i<=mi;i++)
            {    
                if (i == n- 1) 
                 return true;  

                if (s[i] == '0') 
                    q.insert(i); 
                
                if(q.size()>=mini)
                    break;

            }
        }

        return false;  
    }
};