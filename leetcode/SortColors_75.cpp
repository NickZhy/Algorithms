class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(!len) return;
        int i = 0, j = 0, k = 0;
        while(k < len) {
            if(nums[k] == 0) {
                swap(nums[k], nums[j]);
                swap(nums[j++], nums[i++]);
            } else if(nums[k] == 1) {
                swap(nums[k], nums[j++]);
            }
            ++k;
        }
    }
};