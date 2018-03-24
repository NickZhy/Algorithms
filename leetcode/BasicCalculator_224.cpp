class Solution {
public:
    bool isNum(char ch) {
        return '0' <= ch  && ch <= '9';
    }
    
    int readNum(string& s, int& idx) {
        int rst = 0;
        while(isNum(s[idx])) {
            rst *= 10;
            rst += s[idx++] - '0';
        }
        return rst;
    }
    
    void emitOp(vector<int>& nums, char op) {
        int a = nums.back(); nums.pop_back();
        int b = nums.back(); nums.pop_back();
        if(op == '+') {
            nums.push_back(b + a);
        } else {
            nums.push_back(b - a);
        }
    }
    
    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;
        int idx = 0;
        while(idx < s.size()) {
            if(s[idx] == ' ') {
                ++idx;
                continue;
            }
            if(isNum(s[idx])) {
                nums.push_back(readNum(s, idx));
            } else {
                char op = s[idx++];
                if(op == '(') {
                    ops.push_back('(');
                } else {
                    while(ops.size() && ops.back() != '(') {
                        emitOp(nums, ops.back());
                        ops.pop_back();
                    }
                    if(op == ')') {
                        ops.pop_back();
                    } else {
                        ops.push_back(op);
                    }
                }
            }
        }
        while(ops.size()) {
            emitOp(nums, ops.back());
            ops.pop_back();
        }
        return nums.back();
    }
};