class Solution {
public:
    string minWindow(string S, string T) {
        int lenS = S.size(), lenT = T.size();
        if(lenT > lenS) return "";
        if(lenT == lenS) return S.compare(T) == 0? S: "";
        vector<vector<int> > dp(lenS + 1, vector<int>(lenT + 1, lenS + 1));
        for(int i = 0; i <= lenS; ++i) dp[i][0] = 0;
        for(int j = 1; j <= lenT; ++j)
            for(int i = j; i <= lenS; ++i) {
                if(S[i - 1] == T[j - 1]) dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                else dp[i][j] = dp[i - 1][j] + 1;
            }
        int endPos = -1, minLen = INT_MAX;
        for(int i = lenT; i <= lenS; ++i) {
            if(dp[i][lenT] < minLen) {
                minLen = dp[i][lenT];
                endPos = i;
            }
        }
        if(minLen > lenS) return "";
        return S.substr(endPos - minLen, minLen);
    }
};