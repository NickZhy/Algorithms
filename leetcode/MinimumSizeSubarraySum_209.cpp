class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(s <= 0) return 0;
        int start = 0, end = 0, len = nums.size();
        int sum = 0, minLen = INT_MAX;
        while(end < len) {
            while(end < len && sum < s) sum += nums[end++];
            while(start < end && sum - nums[start] >= s) sum -= nums[start++];
            if(sum >= s) minLen = min(minLen, end - start);
            sum -= nums[start++];
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};