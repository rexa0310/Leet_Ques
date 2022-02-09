class Bitset {
public:

  string str, rev;
    int s;
    int counter;
public:
    Bitset(int size) {
        for(int i = 0; i < size; i++) {
            str.push_back('0');
            rev.push_back('1');
        }
        s = size;
        counter  = 0;
    }
    
    void fix(int idx) {
        if(str[idx] == '0') counter++;
        str[idx] = '1';
        rev[idx] = '0';
    }
    
    void unfix(int idx) {
        if(str[idx] == '1') counter--;
        str[idx] = '0';
        rev[idx] = '1';
    }
    
    void flip() {
        swap(str, rev);
        counter = s - counter;
    }
    
    bool all() {
        return counter == s;
    }
    
    bool one() {
        return counter > 0;
    }
    
    int count() {
        return counter;
    }
    
    string toString() {
        return str;
    }
};