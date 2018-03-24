class Solution {
public:
    vector<string> result;
    string input;
    int tar;
    
    bool isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
    long readNum(string& exp, int& pos) {
        long rst = 0;
        while(pos < exp.size() && isNum(exp[pos])) {
            rst *= 10;
            rst += exp[pos++] - '0';
        }
        return rst;
    }
    
    void eval(string exp) {
        int pos = 0;
        long rst = readNum(exp, pos);
        while(pos < exp.size() && exp[pos] == '*') rst *= readNum(exp, ++pos);
        while(pos < exp.size()) {
            char op = exp[pos];
            long curr = readNum(exp, ++pos);
            while(pos < exp.size() && exp[pos] == '*') curr *= readNum(exp, ++pos);
            if(op == '+') rst += curr;
            else rst -= curr;
        }
        if(rst == tar) result.push_back(exp);
    }
    
    bool canAttachNum(string& exp) {
        int len = exp.size();
        if(!len) return true;
        if(exp[len - 1] != '0') return true;
        if(len >= 2 && isNum(exp[len - 2])) return true;
        return false;
    }
    
    void dfs(string num, string exp) {
        if(num.size() == 0) {
            eval(exp);
            return;
        }
        if(canAttachNum(exp)) {
            if(num.size() > 1) {
                dfs(num.substr(1), exp + num[0] + "*");
                dfs(num.substr(1), exp + num[0] + "+");
                dfs(num.substr(1), exp + num[0] + "-");
            }
            dfs(num.substr(1), exp + num[0]);
        }
    }
    
    vector<string> addOperators(string num, int target) {
        if(!num.size()) return vector<string>();
        input = num;
        tar = target;
        string op = "";
        dfs(num, op);
        return result;
    }
};