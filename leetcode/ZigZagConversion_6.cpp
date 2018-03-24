class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> rst(numRows--);
        int pos = numRows, len = numRows * 2;
        for(char ch: s) {
            rst[abs(pos - numRows)] += ch;
            pos = (pos + 1) % len;
        }
        string result = "";
        for(string& r: rst) result += r;
        return result;
    }
};