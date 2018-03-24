typedef pair<char, char> pr;
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<pr> regex;
        for(int i = 0; i < p.size(); ++i) {
            if(i < p.size() - 1 && p[i + 1] == '*') {
                regex.push_back(pr(p[i++], '*'));
            } else 
                regex.push_back(pr(p[i], '\0'));
        }
        int n = s.size();
        int m = regex.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                bool match = i > 0 && (regex[j - 1].first == s[i - 1] || regex[j - 1].first == '.');
                if(regex[j - 1].second == '*') 
                    dp[i][j] = (match && dp[i - 1][j]) || dp[i][j - 1];
                else if(match)
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};