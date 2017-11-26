class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int pf = 0;
        for(int i = 1; i < len; ++i) {
            pf += max(0, prices[i] - prices[i - 1]);
        }
        return pf;
    }
};
