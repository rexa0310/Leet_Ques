class Solution {
public:
    int ans=0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
         vector<int> count(26, 0), used(26, 0);
        for (auto & c : letters) 
            count[c-'a']++;
        
        backtrack(words, score, count, used, 0, 0);
        return ans;
    }
    
    void backtrack(vector<string>&words,vector<int>&score,vector<int>&count,vector<int>&used,int idx,int sum)
    {
        for(int i=0;i<26;i++)
            if(used[i]>count[i])
                return;
        
        ans=max(ans,sum);
            for (int i = idx; i < words.size(); ++i)
            {
            for (auto & c : words[i])
            {
                used[c-'a']++;
               sum += score[c-'a'];
            }
            backtrack(words, score, count, used, i+1, sum);
            for (auto & c : words[i])
            {
                used[c-'a']--;
                sum -= score[c-'a'];
            }
        }
    }
};
    