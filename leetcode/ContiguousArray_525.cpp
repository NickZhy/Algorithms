class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int zeros = 0, ones = 0, maxLen = 0;
        for(int i = 0; i < nums.size(); ++i) {
            zeros += !nums[i];
            ones += nums[i];
            int diff = ones - zeros;
            if(mp.count(diff)) {
                maxLen = max(maxLen, i - mp[diff]);
            }else {
                mp[diff] = i;
            }
        }
        return maxLen;
    }
};