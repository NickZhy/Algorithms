class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])
                nums.erase(nums.begin() + i);
        }
        return nums.size();
    }
};