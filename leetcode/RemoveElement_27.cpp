class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0, curr = 0;
        while(idx < nums.size()) {
            if(nums[idx] != val) 
                nums[curr++] = nums[idx];
            ++idx;
        }
        return curr;
    }
};