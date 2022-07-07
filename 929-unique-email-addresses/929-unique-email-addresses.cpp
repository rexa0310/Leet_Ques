class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
      unordered_set<string> st;
        
        for(string x : emails)
        {    
            int idx = x.find('@'); 
            string a = x.substr(idx); 
            string b = "";
            
            for(int i = 0; i < idx; i++)
            {
                if(x[i] == '+') 
                    break;
                else if(x[i] == '.')
                    continue;
                else 
                    b.push_back(x[i]);
            }
           st.insert(b + a);
        }
        
        return st.size();   
    }
};