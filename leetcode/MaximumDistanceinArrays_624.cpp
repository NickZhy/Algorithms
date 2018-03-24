class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = INT_MIN, lo = arrays[0][0], hi = arrays[0][arrays[0].size() - 1];
        for(int i = 1; i < arrays.size(); ++i) {
            int l = arrays[i][0], h = arrays[i][arrays[i].size() - 1];
            maxDist = max(maxDist, max(abs(hi - l), abs(h - lo)));
            lo = min(lo, l);
            hi = max(hi, h);
        }
        return maxDist;
        
    }
};