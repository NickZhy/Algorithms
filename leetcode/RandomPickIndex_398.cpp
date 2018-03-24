class Solution {
public:
    vector<int> vec;
    Solution(vector<int> nums): vec(nums) {}
    
    int pick(int target) {
        int rst = -1;
        int count = 0;
        for(int i = 0; i < vec.size(); ++i) {
            if(vec[i] == target) {
                ++count;
                if(rand() % count == 0) rst = i;
            }
        }
        return rst;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */