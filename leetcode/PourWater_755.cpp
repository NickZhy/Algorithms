class Solution {
public:
 vector<int> pourWater(vector<int>& heights, int V, int K) {
        vector<int> rst = heights;
        int len = rst.size();
        for(int i = 0; i < V; ++i) {
            int mVal = rst[K];
            int mPos = K;
            int curr = K - 1;
            while(curr >= 0 && rst[curr] <= rst[curr + 1]) {
                if(rst[curr] < mVal) {
                    mVal = rst[curr];
                    mPos = curr;
                }
                --curr;
            }
            if(mPos != K) {
                ++rst[mPos];
                continue;
            }
            curr = K + 1;
            while(curr < len && rst[curr] <= rst[curr - 1]) {
                if(rst[curr] < mVal) {
                    mVal = rst[curr];
                    mPos = curr;
                }
                ++curr;
            }
            ++rst[mPos];
        }
        return rst;
    }

};