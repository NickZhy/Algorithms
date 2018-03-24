class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int minVal = INT_MIN;
        int buyOne = minVal, sellOne = 0, buyTwo = minVal, sellTwo = 0;
        for(int p: prices) {
            sellTwo = max(sellTwo, p + buyTwo);
            buyTwo = max(buyTwo, -p + sellOne);
            sellOne = max(sellOne, p + buyOne);
            buyOne = max(buyOne, -p);
        }
        return max(sellOne, sellTwo);
    }
};