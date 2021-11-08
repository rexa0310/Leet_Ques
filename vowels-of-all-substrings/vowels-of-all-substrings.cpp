class Solution {
public:
    bool check(char a)
    {
        if(a=='a' ||a=='e'||a=='i'||a=='o'||a=='u')
            return true;
        return false;
    }
    long long countVowels(string word) {
        long long int s=0;
      long long   int n=word.length();
         for(int i=0;i<n;i++)
         {
             if(check(word[i]))
                 s=s+((n-i)*(i+1));
         }
        return s;
    }
};