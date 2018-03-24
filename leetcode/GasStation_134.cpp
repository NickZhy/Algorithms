class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if(!len) return -1;
        int curr = 0, j = 0;
        for(int i = 0; i < len; i += j + 1) {
            curr = gas[i];
            for(j = 0; j < len; ++j) {
                curr -= cost[(i + j) % len];
                if(curr < 0) break;
                curr += gas[(i + j + 1) % len];
            }
            if(j == len) return i;
        }
        return -1;
    }
};