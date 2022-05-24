class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
             sort(v.begin(), v.end());
      int ans = 0;
      int i=0, j=v.size()-1;
      while(i < j)
      {
        if(v[i] + v[j] == k)
        {    
          ans++; i++; j--;
        } 
		else if(v[i] + v[j] > k)
            j--;  
        else
            i++;   
      }
      return ans;

    }
};