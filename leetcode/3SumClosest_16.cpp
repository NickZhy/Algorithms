class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDist = INT_MAX;
        int rst = 0;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            int start = i + 1;
            int end = len - 1;
            long a = nums[i];
            while(start < end) {
                long currSum = a + nums[start] + nums[end];
                int dist = abs(currSum - target);
                if(dist < minDist) {
                    minDist = dist;
                    rst = currSum;
                }
                if(currSum < target) {
                    ++start;
                } else {
                    --end;
                }
            }
        }
        return rst;
    }
};