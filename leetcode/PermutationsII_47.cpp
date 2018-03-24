class Solution {
public:
    void perm(vector<int> nums, int i, vector<vector<int>>& rst) {
        if(i == nums.size()){
            rst.push_back(nums);
            return;
        } 
        
        for(int n = i; n < nums.size(); ++n) {
            if(n == i || nums[i] != nums[n]) {
                swap(nums[i], nums[n]);
                perm(nums, i + 1, rst);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rst;
        perm(nums, 0, rst);
        return rst;
    }
};