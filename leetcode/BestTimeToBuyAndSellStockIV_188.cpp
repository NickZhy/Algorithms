class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(!len) return 0;
        if(k > len/2) {
            int pf = 0;
            for(int i = 1; i < len; ++i)
                pf += max(0, prices[i]-prices[i-1]);
            return pf;
        }
        vector<vector<int>> dp1(len, vector<int>(len, 0));
        for(int i = 0; i < len; ++i) {
            int minPri = prices[i];
            for(int j = i + 1; j < len; ++j) {
                dp1[i][j] = max(dp1[i][j - 1], prices[j] - minPri);
                minPri = min(minPri, prices[j]);
            }
        }
        
        vector<int> dp2(len + 1, 0);
        for(int i = 1; i <= k; ++i)
            for(int j = len; j > 0; --j) {
                int maxPft = INT_MIN;
                for(int m = 0; m < j ;++m)
                    maxPft = max(maxPft, dp2[m] + dp1[m][j - 1]);
                dp2[j] = maxPft;
            }
        return dp2[len];
    }
};