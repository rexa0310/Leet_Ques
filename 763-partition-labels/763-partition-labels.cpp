class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        
        int arr[26];
        memset(arr,0,sizeof(arr));
   
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']=i;
        }
        int j=0;
        vector<int>ans;
        
        while(j<s.length())
        {
           int l=arr[s[j]-'a'];
            int i=j;
               int c=0;
            while(i!=l)
            {
                if(arr[s[i]-'a']>l)
                l=arr[s[i]-'a'];
                
                c++;
                i++;
            }
            j=i+1;
            ans.push_back(c+1);
            
        }
        return ans;
    }
};