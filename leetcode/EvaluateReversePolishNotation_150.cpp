class Solution {
public:
    bool isSymbol(string str) {
        if(str.size() != 1) return false;
        return str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/';
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> rst;
        for(string& tk: tokens) {
            if(isSymbol(tk)) {
                assert(rst.size() > 1);
                int b = rst.back(); rst.pop_back();
                int a = rst.back(); rst.pop_back();
                switch(tk[0]) {
                    case '+': a += b; break;
                    case '-': a -= b; break;
                    case '*': a *= b; break;
                    case '/': a /= b; break;
                }
                rst.push_back(a);
            } else {
                rst.push_back(stoi(tk));
            }
        }
        return rst[0];
    }
};