class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& n1, vector<int>& n2)
    {
     long n = n1.size(), dif= 0, dec = 0;
        
	set<int> s(begin(n1), end(n1));   
	for(int i = 0; i < n; i++)
    {
		long curr = abs(n1[i] - n2[i]);   
		 dif+= curr;
	
		auto it = s.lower_bound(n2[i]);
		if(it != begin(s))
            dec = max(dec, curr - abs(*prev(it) - n2[i]));
		if(it != end(s)) 
            dec = max(dec, curr - abs(*it - n2[i]));            
	}

	return (dif - dec) % 1000000007;   
    }
};