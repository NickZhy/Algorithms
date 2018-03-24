class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        if(!len) return true;
        unordered_set<string> dict;
        int maxLen = 0;
        for(string& wd: wordDict) {
            maxLen = max(maxLen, int(wd.size()));
            dict.insert(wd);
        }
        
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 1; i <= len; ++i)
            for(int j = 1; j <= maxLen && j <= i; ++j)
                if(dict.count(s.substr(i - j, j)) && dp[i - j]) {
                    dp[i] = true;
                    break;
                }
        return dp[len];
    }
};