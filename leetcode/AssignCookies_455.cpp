class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, content = 0;
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                ++i; ++j;
                ++content;
            }  else {
                ++j;
            }
        }
        return content;
        //if(g[i] <= s[j]) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
    }
};