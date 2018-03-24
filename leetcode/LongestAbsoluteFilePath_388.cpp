class Solution {
public:
    string getOne(string& input, int& idx) {
        if(idx >= input.size()) return "";
        string rst = "";
        while(idx < input.size() && input[idx] != '\n') {
            rst += input[idx++];
        }
        return rst;
    }
    
    bool isFile(string& f) {
        for(int i = f.size() - 1; i >= 0; --i)
            if(f[i] == '.') return true;
        return false;
    }
    
    int lengthLongestPath(string input) {
        vector<string> stk;
        int currLen = 0;
        int maxLen = 0;
        int idx = 0;
        while(idx < input.size()) {
            int num = 0;
            while(input[idx] == '\t') {
                ++idx; ++num;
            }
            while(stk.size() > num) {
                currLen -= stk.back().size();
                stk.pop_back();
            }
            string name = getOne(input, idx);
            stk.push_back(name);
            currLen += name.size();
            if(isFile(name)) {
                int tmp = stk.size() + currLen - 1;
                maxLen = max(maxLen, tmp);
            }
            ++idx;
        }
        return maxLen;
    }
};