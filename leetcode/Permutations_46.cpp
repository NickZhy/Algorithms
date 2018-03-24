class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rst;
        int len = nums.size();
        if(!len) return rst;
        
        vector<int> tmp;
        tmp.push_back(nums[0]);
        rst.push_back(tmp);
        
        for(int i = 1; i < len; ++i) {
            int currLen = rst.size();
            for(int j = 0; j < currLen; ++j) {
                rst[j].push_back(nums[i]);
                for(int k = 0; k < i; ++k) {
                    tmp = rst[j];
                    if(tmp[k] == tmp[i]) continue;
                    swap(tmp[k], tmp[i]);
                    rst.push_back(tmp);
                }
            }
        }
        return rst;
    }
};