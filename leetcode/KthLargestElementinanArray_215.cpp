class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        k = len - k;
        int s = 0, e = len - 1;
        while(s < e) {
            int t1 = s, t2 = s + 1;
            while(t2 <= e) {
                if(nums[t2] <= nums[s]) swap(nums[++t1], nums[t2]);
                ++t2;
            }
            swap(nums[t1], nums[s]);
            if(t1 - s == k) return nums[t1];
            if(t1 - s > k) {
                e = t1 - 1;
            } else {
                k = k - (t1 - s) - 1;
                s = t1 + 1;
            }
        }
        return nums[s];
    }
};