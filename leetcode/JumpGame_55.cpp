class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canReach = 1;
        for(int i = 0; i < canReach; ++i) {
            canReach = max(canReach, nums[i] + i + 1);
            if(canReach >= nums.size()) return true;
        }
        return false;
    }
};