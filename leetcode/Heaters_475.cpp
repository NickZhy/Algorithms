class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int idx = 0, minLen = 0;
        for(int i = 0; i < houses.size(); ++i) {
            while(idx + 1 < heaters.size() && abs(heaters[idx + 1] - houses[i]) <= abs(heaters[idx] - houses[i])) ++idx;
            minLen = max(minLen, abs(houses[i] - heaters[idx]));
        }
        return minLen;
    }
};