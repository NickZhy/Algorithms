class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rst = 0;
        for(int n: nums)
            rst ^= n;
        return rst;
    }
};