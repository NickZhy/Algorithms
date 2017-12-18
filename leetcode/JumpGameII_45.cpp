class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int maxReach = 0;
        int canReach = 0;
        int len = nums.size();
        for(int i = 0; i < len - 1; ++i) {
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach >= len - 1) return jumps + 1;
            if(i == canReach) {
                ++jumps;
                if(maxReach == canReach) return -1;
                canReach = maxReach;
            }
        }
        return jumps;
    }
};
