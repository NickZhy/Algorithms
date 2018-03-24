class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int h = costs.size();
        if(!h) return 0;
        int c = costs[0].size();
        if(!c) return 0;
        
        int minColor1 = -1, minColor2 = -1;
        int minCost1 = 0, minCost2 = 0;
        for(int i = 0; i < h; ++i) {
            int mCost1 = INT_MAX, mCost2 = INT_MAX;
            int mColor1 = -1, mColor2 = -1;
            for(int j = 0; j < c; ++j) {
                int curr;
                if(j != minColor1) curr =  costs[i][j] + minCost1;
                else curr = costs[i][j] + minCost2;
                if(curr < mCost1) {
                    mCost2 = mCost1;
                    mColor2 = mColor1;
                    mCost1 = curr;
                    mColor1 = j;
                } else if(curr < mCost2) {
                    mCost2 = curr;
                    mColor2 = j;
                }
            }
            minColor1 = mColor1;
            minColor2 = mColor2;
            minCost1 = mCost1;
            minCost2 = mCost2;
        }
        return minCost1;
    }
};