class Solution {
   private:
     bool isVowel(char c) 
     {
       if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            return true;
        return false;
    }
    int countatMost(string &s, int k)
      {
        int ans = 0,n = s.size();
        int i=0;
        unordered_map<char, int> cnt;
        for (int j=0;j<n; ++j)
         {
            if (!isVowel(s[j]))
            {
                i = j + 1;
                cnt.clear();
                continue;
            }
           else
             {
               cnt[s[j]]++;
              while(cnt.size()>k)
              {
               cnt[s[i]]--;
               if(cnt[s[i]]==0)
                   cnt.erase(s[i]);
              i++;
               }
              ans+=j-i+1;
            }
        }
        return ans;
    }
public:
    int countVowelSubstrings(string s)
        {       
            return countatMost(s, 5) - countatMost(s, 4);
        }
};