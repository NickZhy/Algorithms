class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int fst = 0, sec = 0;
        /*  input 1: 00 -> 01 -> 10 -> 00 -> 01 -> 10 -> ...
            fst: 0 -> 0 -> 1 -> 0 -> 0 -> 1 -> ...
            sec: 0 -> 1 -> 0 -> 0 -> 1 -> 0 -> ...
            fst     sec     input   ->  fst     sec
            0       0       0           0       0
            1       0       0           1       0
            0       1       0           0       1
            
            0       0       1           0       1
            0       1       1           1       0
            1       0       1           0       0
        */
        for(int n: nums) {
            sec = (sec ^ n) & ~fst;
            fst = (fst ^ n) & ~sec;
        }
        return sec;
    }
};