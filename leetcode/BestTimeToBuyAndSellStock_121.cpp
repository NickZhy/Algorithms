class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPri = INT_MAX;
        int maxPro = 0;
        for(int p: prices) {
            maxPro = max(maxPro, p - minPri);
            minPri = min(minPri, p);
        }
        return maxPro;
    }
};