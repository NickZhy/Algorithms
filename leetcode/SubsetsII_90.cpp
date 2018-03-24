class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> rst(1);
        int len = nums.size();
        if(!len) return rst;
        
        unordered_map<int, int> counts;
        for(int n: nums) ++counts[n];
        
        for(pair<int, int> p: counts) {
            int currLen = rst.size();
            for(int i = 0; i < currLen; ++i)
                for(int j = 1; j <= p.second; ++j) {
                    vector<int> tmp = rst[i];
                    for(int k = 0; k < j; ++k)
                        tmp.push_back(p.first);
                    rst.push_back(tmp);
                }
        }
        return rst;
    }
};