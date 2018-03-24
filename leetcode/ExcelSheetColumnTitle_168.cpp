class Solution {
public:
    string convertToTitle(int n) {
        string rst = "";
        do {
            int t = n % 26;
            if(t == 0) {
                rst += 'Z';
                --n;
            } else {
                rst += 'A' + t - 1;
            }
            n /= 26;
        } while(n);
        reverse(rst.begin(), rst.end());
        return rst;
    }
};