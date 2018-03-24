class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> pd(len, vector<bool>(len, false));
        for(int i = len - 1; i >= 0; --i)
            for(int j = i; j < len; ++j)
                if(s[i] == s[j]) {
                    if(i + 1 >= j - 1) {
                        pd[i][j] = true;
                    } else
                        pd[i][j] = pd[i + 1][j - 1];
                }
        // for(int i = 0; i < len; ++i) {
        //     for(int j = 0; j < i; ++j)
        //         cout << "  ";
        //     for(int j = i; j < len; ++j)
        //         cout << pd[i][j] << " ";
        //     cout << endl;
        // }
        vector<int> dp(s.size() + 1, false);
        dp[0] = 0;
        for(int i = 1; i <= s.size() ; ++i) {
            int mCut = INT_MAX;
            if(pd[0][i-1]) {
                mCut = 0;
            } else {
                for(int j = 1; j < i; ++j) {
                    if(pd[j][i-1])
                        mCut = min(mCut, dp[j] + 1);
                }
            }
            dp[i] = mCut;
        }
        return dp[s.size()];
    }
};