// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i = 0, j = n - 1;
        while(i < j) {
            if(knows(i, j)) ++i;
            else --j;
        }
        for(int m = 0; m < n; ++m)
            if(m != i && (!knows(m, i) || knows(i, m))) return -1;
        return i;
    }
};