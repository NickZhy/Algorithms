class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        if(!len) return 0;
        long sum = 0;
        unordered_map<long, int> histSum;
        histSum[0] = -1;
        int maxLen = 0;
        for(int i = 0; i < len; ++i) {
            sum += nums[i];
            if(histSum.count(sum - k)) {
                int prevIdx = histSum[sum - k];
                maxLen = max(maxLen, i - prevIdx);
            }
            if(!histSum.count(sum)) histSum[sum] = i;
        }
        return maxLen;
    }
};