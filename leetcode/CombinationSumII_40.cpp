class Solution {
public:
    void dfs(int pos, int target, vector<int>& currRst, vector<int>& candidates, vector<vector<int>>& rst) {
        if(target == 0) rst.push_back(currRst);
        if(pos >= candidates.size() || candidates[pos] > target) return;
        currRst.push_back(candidates[pos]);
        dfs(pos + 1, target - candidates[pos], currRst, candidates, rst);
        currRst.pop_back();
        while(pos + 1 < candidates.size() && candidates[pos + 1] == candidates[pos]) ++pos;
        dfs(pos + 1, target, currRst, candidates, rst);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> rst;
        vector<int> currRst;
        dfs(0, target, currRst, candidates, rst);
        return rst;
    }
};