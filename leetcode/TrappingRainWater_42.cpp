class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len <= 1) return 0;
        int start = 0, end = len - 1;
        int lMax = 0, rMax = 0, rst = 0;
        while(start < end) {
            lMax = max(lMax, height[start]);
            rMax = max(rMax, height[end]);
            if(lMax < rMax) {
                rst += lMax - height[start++];
            } else {
                rst += rMax - height[end--];
            }
        }
        return rst;
    }
};