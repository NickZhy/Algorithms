class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int rst = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int s = i + 1, e = len - 1;
            while(s < e) {
                if(nums[i] + nums[s] + nums[e] < target) {
                    rst += e - s;
                    ++s;
                } else {
                    --e;
                }
            }
        }
        return rst;
    }
};