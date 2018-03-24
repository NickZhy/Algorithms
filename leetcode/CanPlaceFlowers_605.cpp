class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(len < 1) return 0;
        vector<int> dp(len + 1, 0);
        if(flowerbed[0] == 0 && (len == 1 || flowerbed[1] == 0)) dp[1] = 1;
        for(int i = 1; i < len; ++i) {
            bool l = (i == 0 || flowerbed[i - 1] == 0);
            bool r = (i == len - 1 || flowerbed[i + 1] == 0);
            if(!flowerbed[i] && l && r) {
                dp[i + 1] = max(1 + dp[i - 1], dp[i]);
            } else {
                dp[i + 1] = dp[i];
            }
        }
      //  cout << dp[len] << endl;
        return dp[len] >= n;
    }
};
