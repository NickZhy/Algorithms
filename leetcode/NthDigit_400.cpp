/*  1  ~ 9    9   * 1
    10 ~ 99   90  * 2
    100 ~ 999 900 * 3
    numbers having length i: 9 * 10 ^ (i - 1) * i
*/
class Solution {
public:
    int findNthDigit(int n) {
        int nLen = 1;
        long num = 1;
        while(n > 9 * num * nLen) {
            n -= 9 * num * nLen;
            num *= 10;
            ++nLen;
        }
        // now find the n-th digit within numbers with length nLen
        --n; // counting from 0
        long target = num + n / nLen;
        long nth = n % nLen;
        return target / (long)pow(10, nLen - 1 - nth) % 10;
    }
};