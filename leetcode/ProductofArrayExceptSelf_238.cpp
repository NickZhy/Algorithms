class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(!len) return {};
        vector<int> prod(len + 1, 0);
        prod[0] = 1;
        for(int i = 1; i <= len; ++i)
            prod[i] = prod[i - 1] * nums[i - 1];
        int invProd = 1;
        
        vector<int> rst(len, 0);
        for(int i = len - 1; i >= 0; --i) {
            rst[i] = prod[i] * invProd;
            invProd *= nums[i];
        }
        return rst;
    }
};