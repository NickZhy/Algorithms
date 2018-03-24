class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int n: nums) numSet.insert(n);
        unordered_set<int> visited;
        int result = 0;
        for(int n: nums) {
            if(visited.count(n)) continue;
            int maxLeft = 0;
            while(numSet.count(n - 1 - maxLeft)) {
                visited.insert(n - 1 - maxLeft);
                ++maxLeft;
            }
            int maxRight = 0;
            while(numSet.count(n + 1 + maxRight)) {
                visited.insert(n + 1 + maxRight);
                ++maxRight;
            }
            result = max(result, maxLeft + maxRight + 1);
        }
        return result;
    }
};