class Solution {
public:
    bool splitable(vector<int>& nums, int m, long max) {
        if(m >= nums.size()) return true;
        long sum = 0, seg = 1;
        for(int i = 0; i < nums.size(); ++i) {
            if(sum + nums[i] > max) {
                ++seg;
                sum = 0;
            }
            sum += nums[i];
        }
        return seg <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        long lo = nums[0], hi = 0;
        for(int n: nums) {
            hi += n;
            lo = max(lo, (long)n);
        }
        if(splitable(nums, m, lo)) return lo;
        while(lo + 1 < hi) {
            long mid = lo + (hi - lo) / 2;
            if(splitable(nums, m, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};