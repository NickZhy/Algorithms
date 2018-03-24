// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 0, end = n;
        while(start < end) {
            int mid = start + (end - start) / 2;
            int t = guess(mid);
            if(t == 0) return mid;
            if(t > 0) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};