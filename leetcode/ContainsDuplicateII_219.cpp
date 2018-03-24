class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int idx = 0;
        while(idx < nums.size()) {
            if(window.count(nums[idx])) return true;
            window.insert(nums[idx]);
            if(idx >= k) window.erase(nums[idx - k]);
            ++idx;
        }
        return false;
    }
};