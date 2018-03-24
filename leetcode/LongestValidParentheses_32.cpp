typedef pair<int, bool> pr;
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<pr> stk;
        stk.push_back(pr(-1, false));
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                stk.push_back(pr(i, true));
            } else {
                if(stk.back().second) {
                    stk.pop_back();
                } else {
                    stk.push_back(pr(i, false));
                }
            }
        }
        int maxLen = 0;
        stk.push_back(pr(s.size(), false));
        for(int i = 0; i < stk.size() - 1; ++i)
            maxLen = max(maxLen, stk[i + 1].first - stk[i].first - 1);
        return maxLen;
    }
};