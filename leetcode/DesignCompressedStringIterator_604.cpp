class StringIterator {
    vector<pair<char, int>> data;
    int idx, offset;
public:
    StringIterator(string compressedString) {
        string& str = compressedString;
        int i = 0;
        while(i < str.size()) {
            char ch =  str[i++];
            int num = 0;
            while(i < str.size() && isdigit(str[i])) 
                num = 10 * num + str[i++] - '0';
            if(num == 0) 
                num = 1;
            data.push_back(pair<char, int>(ch, num));
        }
        idx = offset = 0;
    }
    
    char next() {
        if(!hasNext()) return ' ';
        char rst = data[idx].first;
        ++offset;
        if(offset >= data[idx].second) {
            ++idx;
            offset = 0;
        }
        return rst;
    }
    
    bool hasNext() {
        if(idx >= data.size()) 
            return false;
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */