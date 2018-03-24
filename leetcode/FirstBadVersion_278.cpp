// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        if(isBadVersion(i)) return i;
        while(i + 1 < j) {
            int mid = i + (j - i) / 2;
            if(isBadVersion(mid)) {
                j = mid;
            } else {
                i = mid;
            }
        }
        return j;
    }
};