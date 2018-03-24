class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> rst;
        int start = 0, end = 0;
        while(end < nums.size()) {
            while(end + 1 < nums.size() && nums[end + 1] == nums[end] + 1) ++end;
            if(start == end) {
                rst.push_back(to_string(nums[start]));
            } else {
                string r = to_string(nums[start]) + "->" + to_string(nums[end]);
                rst.push_back(r);
            }
            start = ++end;
        }
        return rst;
    }
};