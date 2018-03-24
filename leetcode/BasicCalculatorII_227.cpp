class Solution {
public:
    bool isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
    int readNum(string& s, int& idx) {
        int rst = 0;
        while(idx < s.size() && isNum(s[idx])) {
            rst *= 10;
            rst += s[idx++] - '0';
        }
        return rst;
    }
    
    void emitOp(vector<int>& nums, char op) {
        assert(nums.size() > 1);
        int b = nums.back(); nums.pop_back();
        int a = nums.back(); nums.pop_back();
        switch(op) {
            case '+': nums.push_back(a + b); break;
            case '-': nums.push_back(a - b); break;
            case '*': nums.push_back(a * b); break;
            case '/': assert(b != 0); nums.push_back(a / b); break;
        }
    }
    
    int calculate(string s) {
        unordered_map<char, int> prior;
        prior['+'] = prior['-'] = 1;
        prior['*'] = prior['/'] = 2;
        int idx = 0;
        vector<int> nums;
        vector<char> ops;
        while(idx < s.size()) {
            if(s[idx] == ' ') {
                ++idx;
                continue;
            }
            if(isNum(s[idx])) {
                nums.push_back(readNum(s, idx));
            } else {
                char op = s[idx++];
                while(ops.size()) {
                    char lastOp = ops.back();
                    if(prior[lastOp] < prior[op]) break;
                    emitOp(nums, lastOp);
                    ops.pop_back();
                }
                ops.push_back(op);
            }
        }
        while(ops.size()) {
            emitOp(nums, ops.back());
            ops.pop_back();
        }
        return nums.back();
    }
};