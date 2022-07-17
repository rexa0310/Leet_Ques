typedef pair<int,int> pii;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        priority_queue<pii, vector<pii>, greater<pii> >pq;
        int n = apples.size();
        int c = 0;
        
        for(int i = 0; i<n || !pq.empty(); i++)
        {
             
            if(i < n && apples[i])
              pq.push(make_pair(i+days[i],apples[i]));
              
            
            while(!pq.empty() && i >= pq.top().first)
              pq.pop();
           
           
             if(!pq.empty())
             {
                     auto p = pq.top(); 
                     pq.pop();
                     
                   
                    if(i < n )  
                    {
                        c ++ ;   
                        p.second--;        
                        if(p.second > 0)
                        pq.push(p);
                    }
                    else
                    {
                         
                         int add = min(p.first - i ,p.second);
                         c += add;
                         i += add - 1;
                         
                    }
             }
           
        }
       
        return c;
       
    }
};