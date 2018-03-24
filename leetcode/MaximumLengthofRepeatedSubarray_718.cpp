class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size(), len2 = B.size();
        if(!len1 || !len2) return 0;
        vector<int> dp(len2 + 1, 0);
        int maxLen = 0;
        for(int i = 1; i <= len1; ++i) {
            for(int j = len2; j >= 1; --j) {
                if(A[i - 1] == B[j - 1])
                    dp[j] = dp[j - 1] + 1;
                else
                    dp[j] = 0;
              maxLen = max(maxLen, dp[j]);
            }
        }
        return maxLen;
    }
};