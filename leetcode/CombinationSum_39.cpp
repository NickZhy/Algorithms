class Solution {
public:
    void helper(int pos, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& rst) {
        if(target == 0) {
            rst.push_back(curr);
            return;
        }
        if(pos >= candidates.size()) return;
        
        int num = candidates[pos];
        helper(pos + 1, candidates, target, curr, rst);
        for(int i = 1; i * num <= target; ++i) {
            curr.push_back(num);
            helper(pos + 1, candidates, target - i * num, curr, rst);
        }
        for(int i = 1; i <= target/num; ++i) 
            curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rst;
        vector<int> curr;
        helper(0, candidates, target, curr, rst);
        return rst;
    }
};