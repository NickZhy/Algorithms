class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rst = 0;
        for(int i = 0; i < 32; ++i) {
            if(n & (1 << i))
                rst |= 0x80000000 >> i;
        }
        return rst;
    }
};