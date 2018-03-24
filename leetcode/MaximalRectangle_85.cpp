typedef pair<int, int> pr;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int hei = matrix.size();
        if(!hei) return 0;
        int wid = matrix[0].size();
        if(!wid) return 0;
        vector<int> hist(wid, 0);
        int maxRect = 0;
        for(int i = 0; i < hei; ++i) {
            for(int j = 0; j < wid; ++j) {
                if(matrix[i][j] == '1') {
                    ++hist[j];
                } else {
                    hist[j] = 0;
                }
            }
            maxRect = max(maxRect, largestRectangleArea(hist));
        }
        return maxRect;
    }
    
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
        heights.pop_back();
        return maxRect;
    }
};