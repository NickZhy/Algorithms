typedef pair<int, int> pr;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int len = heights.size();
        vector<pr> stk;
        stk.push_back(pr(heights[0], 0));
        int maxRect = 0;
        for(int i = 1; i < len; ++i) {
            int startIdx = i;
            while(stk.size() && stk.back().first > heights[i]) {
                pr curr = stk.back();
                maxRect = max(maxRect, curr.first * (i - curr.second));
                stk.pop_back();
                startIdx = curr.second;
            }
            stk.push_back(pr(heights[i], startIdx));
        }
        return maxRect;
    }
};