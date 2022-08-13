class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_length=words[0].size();
        int len=s.length();
        int cnt_words=words.size();
        
        unordered_map<string,int>temp,total;
        for(auto x:words)
            total[x]++;
        
        vector<int>res;
        int st=0;
        int cnt=0;
        while(st<=len-word_length)
        {
        //    cout<<st<<" "<<cnt<<endl;
            string cur=s.substr(st,word_length);
            temp[cur]++;
            if(total.find(cur)!=total.end())
            {
                if(temp[cur]>total[cur])
                {
                    st=st+1-(word_length*(cnt));
                    cnt=0;
                    temp.clear();
                  //  cout<<100<<endl;
                }
                else
                {
                    cnt++;
                    if(cnt==cnt_words)
                    {
                        res.push_back(st-(word_length*(cnt-1)));
                        st=st+1-(word_length*(cnt-1));
                        cnt=0;
                        temp.clear();
                     //   cout<<101<<endl;
                    }
                    else
                    {
                        st=st+word_length;
                     //   cout<<102<<endl;
                    }
                }
                
            }
            else
            {
                st=st+1-(word_length*cnt);
                temp.clear();
                cnt=0;
            }
            
        }
        return res;
    }
};