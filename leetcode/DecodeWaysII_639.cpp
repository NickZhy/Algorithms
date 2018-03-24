long M = 1000000007;
class Solution {
public:
    int numDecodings(string s) {
        vector<long> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            int num = 0;
            if(s[i - 1] == '*')
                num = 9;
            else if(s[i - 1] != '0')
                num = 1;
            dp[i] = (dp[i] + (dp[i - 1] * num) % M) % M;
            
            if(i > 1) {
                num = 0;
                if(s[i - 1] == '*') {
                    if(s[i - 2] == '1')
                        num = 9;
                    else if(s[i - 2] == '2')
                        num = 6;
                    else if(s[i - 2] == '*')
                        num = 15;
                } else if (s[i - 2] == '*') {
                    if(s[i - 1] <= '6')
                        num = 2;
                    else
                        num = 1;
                } else {
                    int code = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                    if( code > 9 &&  code <= 26)
                        num = 1;
                }
                dp[i] = (dp[i] + (dp[i - 2] * num) % M) % M;
            }
        }
        return dp[s.size()];
    }
};