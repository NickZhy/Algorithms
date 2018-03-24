// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<char> remains;
    int read(char *buf, int n) {
        int idx = 0;
        while(idx < n && remains.size()) {
            buf[idx++] = remains.front();
            remains.pop();
        }
        char tmp[5];
        int num = 0, rdNum = 0;
        while(idx < n) {
            num = 0;
            rdNum = read4(tmp);
            while(idx < n && num < rdNum) buf[idx++] = tmp[num++];
            if(rdNum < 4) break;
        }
        while(num < rdNum) remains.push(tmp[num++]);
        return idx;
    }
};