// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int idx = 0;
        while(idx < n) {
            char tmp[5];
            int rdNum = read4(tmp);
            for(int i = 0; idx < n && i < rdNum; ++i)
                buf[idx++] = tmp[i];
            if(rdNum < 4) break;
        }
        return idx;
    }
};