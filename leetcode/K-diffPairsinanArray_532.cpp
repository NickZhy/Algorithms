class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < 2) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, rst = 0;
        while(true) {
            while(j < len && nums[j] - nums[i] < k) ++j;
            if(j >= len) break;
            rst += (nums[j] - nums[i] == k);
            ++i;
            while(i < len && nums[i] == nums[i - 1]) ++i;
            j = i + 1;
        }
        return rst;
    }
};