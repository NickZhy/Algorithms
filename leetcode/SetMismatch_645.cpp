class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> rst;
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] != nums[nums[i] - 1]) 
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1) {
                rst.push_back(nums[i]);
                rst.push_back(i + 1);
                break;
            }
        }
        return rst;
    }
};