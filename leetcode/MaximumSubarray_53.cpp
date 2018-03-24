class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size()) return 0;
        long sum = 0;
        long minSum = 0;
        long rst = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            rst = max(rst, sum - minSum);
            minSum = min(minSum, sum);
        }
        return rst;
    }
};