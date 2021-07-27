class Solution {
public:
  vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
vector<string> letterCombinations(string digits)
{
	if(digits.size() == 0) return {};        
	string comb = "";
	solve(digits, 0, comb);
	return ans; 
}

void solve(string &digits, int i, string &comb)
{
	if(i == size(digits))
    {
		ans.push_back(comb);    
		return;
	}
	for(auto c : map[digits[i] - '2'])
    {
		comb.push_back(c);           
		solve(digits, i + 1, comb); 
		comb.pop_back(); 
    }
}
};