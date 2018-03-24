class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        vector<char> stk;
        map<char, char> pr = {{')', '('}, {']', '['}, {'}', '{'}};
        for(char ch: s) {
            if(ch == ')' || ch == ']' || ch == '}') {
                if(!stk.size() || stk.back() != pr[ch]) return false;
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk.size() == 0;
    }
};