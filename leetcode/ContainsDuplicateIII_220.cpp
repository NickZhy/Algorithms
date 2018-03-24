class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;
        if(k < 1) return false;
        
        set<long> window;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > k) window.erase(nums[i - k - 1]);
            set<long>::iterator lb = window.lower_bound(long(nums[i]) - t);
            if(lb != window.end() && long(*lb) - nums[i] <= t)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};