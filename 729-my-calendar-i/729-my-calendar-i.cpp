class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    map<int,int>m;
    bool book(int st, int end) {
       m[st]++;
        m[end]--;
        int c = 0;
        for(auto& x : m)
        {
            c += x.second;
            if(c==2)
            {
                m[st]--;  
                m[end]++;  
                return false;
            }
        }
    
        return true;  
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */