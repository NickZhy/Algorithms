class Solution {
public:
    int numDecodings(string s) {
        if(!s.size()) return 0;
        int last2 = 1;
        int last1 = s[0] != '0';
        for(int i = 1; i < s.size(); ++i) {
            int next = 0;
            if(s[i] != '0')
                next += last1;
            if(i > 0) {
                int code = stoi(s.substr(i - 1, 2));
                if(code >= 10 &&  code <= 26)
                    next += last2;
            }
            last2 = last1;
            last1 = next;
            if(!last1 && !last2) return 0;
        }
        return last1;
    }
};