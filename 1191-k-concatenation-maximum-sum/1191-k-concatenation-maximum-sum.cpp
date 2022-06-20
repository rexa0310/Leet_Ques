#include<bits/stdc++.h>
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& v, int k) {
     
        long ans = 0, cur = 0, s = 0;
	   int M = 1e9 + 7;
	for (int i = 0; i < v.size(); i++)
    {
		cur = max(cur + v[i], (long)v[i]);
		ans = max(ans, cur);
		s += v[i];
	}
	
	if (k < 2)
        return ans % M;
	
       long ans1=0;
	if (s > 0) 
         ans1=(ans + (k - 1) * s) % M;
	
	for (int i = 0; i < v.size(); i++)
    {
		cur = max(cur + v[i], (long)v[i]);
		ans = max(ans, cur);
	}
        long res= max(ans1,ans%M);
	return res;
    }
};