class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int idx = 0, maxLen = 0;
        while(idx < nums.size()) {
            int end = idx;
            while(end + 1 < nums.size() && nums[end] < nums[end + 1]) ++end;
            maxLen = max(maxLen, end - idx + 1);
            idx = end + 1;
        }
        return maxLen;
    }
};