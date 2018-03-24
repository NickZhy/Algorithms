class Solution {
public:
    int numWays(int n, int k) {
        if(n <= 0 || k == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k * k;
        // dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1)
        // ends with two same color dp[i - 2] * (k - 1)
        // ends with no continues color dp[i - 1] * (k - 1)
        int first = k, second = k * k;
        for(int i = 2; i < n; ++i) {
            int tmp = (first + second) * (k - 1);
            first = second;
            second = tmp;
        }
        return second;
    }
};