class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rst;
        unordered_map<int, int> visited;
        for(int i = 0; i < nums.size(); ++i) {
            if(visited.count(target - nums[i])) {
                rst.push_back(visited[target - nums[i]]);
                rst.push_back(i);
            }
            visited[nums[i]] = i;
        }
        return rst;
    }
};