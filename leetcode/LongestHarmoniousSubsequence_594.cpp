class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxLen = 0;
        for(int n: nums) {
            ++mp[n];
            int tmp = max(mp[n - 1], mp[n + 1]);
            if(tmp > 0)
                maxLen = max(maxLen, tmp + mp[n]);
        }
        return maxLen;
    }
};