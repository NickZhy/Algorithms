class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int n: nums)
            xr ^= n;
        
        int mask = 1;
        while(mask && !(mask & xr))
            mask = mask << 1;
        
        int xr2 = 0;
        for(int n: nums)
            if(mask & n)
                xr2 ^= n;
        
        return {xr ^ xr2, xr2};
    }
};