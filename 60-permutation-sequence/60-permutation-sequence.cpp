class Solution {
public:
    void recur(int n, vector<int>&v,string& ans,int k,vector<int>fact)
    {
        if(n==1)
        {
            ans+=to_string(v.back());
            return ;
        }
        
		int index = (k/fact[n-1]);
		if(k % fact[n-1] == 0)
            index--;
        
		
		ans+= to_string(v[index]);  
        v.erase(v.begin() + index); 
        k -= fact[n-1] * index;   
        recur(n-1,v,ans,k,fact);
    }
    string getPermutation(int n, int k) {
        if(n==1)
            return "1";
        vector<int>v(n);
        for(int i=0;i<n;i++)
            v[i]=i+1;
        
        string ans="";
        vector<int>fact = {1,1,2,6,24,120,720,5040,40320,362880};
        recur(n,v,ans,k,fact);
        return ans;
    }
};