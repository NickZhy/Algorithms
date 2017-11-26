class Solution {
public:
    bool cmp(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        while(i < a.size() && a[i] == 0) ++i;
        while(j < b.size() && b[j] == 0) ++j;
        if(a.size() - i > b.size() - j) return true;
        if(a.size() - i < b.size() - j) return false;
        while(i < a.size() && j < b.size()) {
            if(a[i] > b[j]) return true;
            if(a[i] < b[j]) return false;
            ++i; ++j;
        }
        return false;
    }
    
    vector<vector<int>> maxSubseq(vector<int>& nums, int k) {
        int len = nums.size();
        vector<vector<int>> dp(k + 1);
        for(int i = 1; i <= len; ++i) {
            for(int j = min(k, i); j > 0; --j) {
                vector<int> t = dp[j - 1];
                t.push_back(nums[i - 1]);
                dp[j] = cmp(dp[j], t)? dp[j]: t;
            }
        }
        return dp;
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> rst;
        while(i < len1 && j < len2) {
            int cp = 0;
            for(int n = 0; cp == 0 && i + n < len1 && j + n < len2 ;++n) {
                if(nums1[i + n] > nums2[j + n]) cp = 1;
                if(nums1[i + n] < nums2[j + n]) cp = -1;
            }
            if(cp == 1)
                rst.push_back(nums1[i++]);
            else if(cp == -1)
                rst.push_back(nums2[j++]);
            else if(len1 - i > len2 - j)
                rst.push_back(nums1[i++]);
            else
                rst.push_back(nums2[j++]);
                
        }
        while(i < nums1.size())
            rst.push_back(nums1[i++]);
        while(j < nums2.size())
            rst.push_back(nums2[j++]);
        return rst;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int>> dp1 = maxSubseq(nums1, min(len1, k));
        vector<vector<int>> dp2 = maxSubseq(nums2, min(len2, k));
        vector<int> rst;
        for(int i = max(0, k - len2); i <= min(k, len1); ++i) {
            vector<int> t = merge(dp1[i], dp2[k - i]);
            if(cmp(t, rst)) rst = t;
        }
        return rst;
    }
};
