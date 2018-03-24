class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        assert(k <= nums.size());
        int sum = 0;
        for(int i = 0; i < k; ++i)
            sum += nums[i];
        int maxSum = sum;
        for(int i = 0; i + k < nums.size(); ++i) {
            sum = sum + nums[i + k] - nums[i];
            maxSum = max(maxSum, sum);
        }
        return double(maxSum) / k;
    }
};