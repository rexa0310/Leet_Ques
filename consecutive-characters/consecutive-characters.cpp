class Solution {
public:
    int maxPower(string s) {
     int max_len = 0, curr_len = 0;
        char prev = s[0];
        
        for (auto letter : s){
            if (letter == prev)
                curr_len++;
            else
                curr_len = 1;
            
            max_len = max(max_len, curr_len);
            prev = letter;
        }
        
        return max_len;   
    }
};