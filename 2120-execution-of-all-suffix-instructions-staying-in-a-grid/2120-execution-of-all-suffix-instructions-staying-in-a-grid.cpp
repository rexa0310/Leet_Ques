class Solution {
public:
   vector<int> executeInstructions(int n, vector<int>& st, string s) {
        int size=s.size();
        vector<int>ans(size,0);
		
        for(int i=0;i<size;i++)
           ans[i]= findSteps(n,s,st[0],st[1],i);
       
        return ans; 
    }
	
    int findSteps(int &n,string &s,int row,int col,int pos)
    {
       int ans=0;
        for(int i=pos;i<s.size();i++)
        {
            if(s[i]=='L')
                col--;
            else if(s[i]=='R')
                col++;
            else if(s[i]=='U')
                row--;
            else
                row++;
				
            if(row<0 || col<0 || row>=n || col>=n)
                return ans;
				
            ans++;
        }
        return ans;
    
        
    }
};