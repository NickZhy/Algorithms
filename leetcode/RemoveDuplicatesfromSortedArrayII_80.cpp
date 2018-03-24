class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        while(idx < nums.size()) {
            while(idx + 2 < nums.size() && nums[idx + 2] == nums[idx]) 
                nums.erase(nums.begin() + idx);
            ++idx;
        }
        return nums.size();
    }
};