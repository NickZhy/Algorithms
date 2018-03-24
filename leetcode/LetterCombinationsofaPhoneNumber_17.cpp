class Solution {
public:
    string num2char[10] = {" ",  "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string& digits, int pos, string& curr, vector<string>& rst) {
        if(pos == digits.size()) {
            if(curr.size()) rst.push_back(curr);
            return;
        }
        int num = digits[pos] - '0';
        if(num == 1) {
            helper(digits, pos + 1, curr, rst);
        } else {
            for(char ch: num2char[num]) {
                curr.push_back(ch);
                helper(digits, pos + 1, curr, rst);
                curr.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string curr = "";
        vector<string> rst;
        helper(digits, 0, curr, rst);
        return rst;
    }
};