class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> rst;
        int i = 0;
        while(i < len) {
            int start = i + 1, end = len - 1;
            while(start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if(sum > 0) --end;
                else if(sum < 0) ++start;
                else {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[start]);
                    tmp.push_back(nums[end]);
                    rst.push_back(tmp);
                    ++start;
                    while(start < end && nums[start] == nums[start - 1]) ++start;
                }
            }
            ++i;
            while(i < len && nums[i] == nums[i - 1]) ++i;
        }
        return rst;
    }
};