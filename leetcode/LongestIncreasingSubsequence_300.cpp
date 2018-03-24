class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        vector<int> minTail(len + 1, 0);
        int maxLen = 1;
        minTail[1] = nums[0];
        for(int i = 1; i < len; ++i) {
            if(minTail[maxLen] < nums[i]) {
                minTail[++maxLen] = nums[i];
            } else if(nums[i] <= minTail[1]) {
                minTail[1] = nums[i];
            } else {
                int s = 1, e = maxLen;
                while(s + 1 < e) {
                    int m = (s + e) / 2;
                    if(minTail[m] < nums[i]) {
                        s = m;
                    } else {
                        e = m;
                    }
                }
                minTail[s + 1] = nums[i];
            }
        }
        return maxLen;
    }
};