class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long covered = 1, i = 0, need = 0;
        while(covered <= n) {
            if(i < nums.size() && nums[i] <= covered) {
                covered += nums[i++];
            } else {
                covered += covered;
                ++need;
            }
        }
        return need;
    }
};