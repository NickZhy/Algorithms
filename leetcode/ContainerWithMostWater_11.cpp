class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1;
        int maxCap = 0;
        while(l < r) {
            maxCap = max(min(height[l], height[r]) * (r - l), maxCap);
            if(height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return maxCap;
    }
};