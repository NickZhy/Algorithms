class Solution {
public:
    string say(string& str) {
        string rst = "";
        int idx = 0;
        while(idx < str.size()) {
            int count = 0;
            while(idx + count < str.size() && str[idx] == str[idx + count]) ++count;
            rst += to_string(count) + str[idx];
            idx += count;
        }
        return rst;
    }
    
    string countAndSay(int n) {
        string rst = "1";
        for(int i = 1; i < n; ++i)
            rst = say(rst);
        return rst;
    }
};