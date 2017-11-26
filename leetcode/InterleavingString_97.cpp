/*
                    (s3[i+j] == s2[j] && dp[i][j-1])
    dp[i][j] OR
                    (s3[i+j] == s1[i] && dp[i-1][j])
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if(s3.size() != len1 + len2) return false;
        
        vector<bool> dp(len2 + 1);
        dp[0] = true;
        for(int i = 0; i <= len1; ++i)
            for(int j = 0; j <= len2; ++j) {
                if(i + j == 0) continue;
                bool t1 = false, t2 = false;
                if(i > 0)
                    t1 = s1[i - 1] == s3[i + j - 1] && dp[j];
                if(j > 0)
                    t2 = s2[j - 1] == s3[i + j - 1] && dp[j - 1];
                dp[j] = t1 || t2;
                
            }
        return dp[len2];
    }
};
