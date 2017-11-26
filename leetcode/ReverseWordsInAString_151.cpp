class Solution {
public:
    void reverseWords(string &s) {
        int tmp = 0;
        while(s[tmp] == ' ') ++tmp;
        if(tmp)
            s.erase(0, tmp);
        
        tmp = s.size() - 1;
        while(s[tmp] == ' ') --tmp;
        if(tmp < s.size() - 1)
            s.erase(s.begin() + tmp + 1, s.end());
        
        tmp = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                if(i > tmp) 
                    reverse(s.begin() + tmp, s.begin() + i);

                tmp = i + 1;
            }
        }
        if(tmp != s.size())
            reverse(s.begin() + tmp, s.end());
        
        reverse(s.begin(), s.end());
        tmp = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] != ' ') {
                if(tmp > 1) 
                    s.erase(i + 1, tmp - 1);
                tmp = 0;
            } else {
                ++tmp;
            }
        }
    }
};
