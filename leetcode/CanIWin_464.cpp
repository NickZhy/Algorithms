class Solution {
    int maxInt;
    unordered_map<long, bool> mp;
public:
    void showBit(int bit) {
        for(int i = 1; i <= maxInt; ++i)
            cout << ((bit & (1 << i)) != 0);
    }
    
    long zipInt(long a, long b) {
        return (a << 32) | b;
    }
    
    bool canWin(int bit, int desiredTotal) {
        long p = zipInt(bit, desiredTotal);
        if(mp.count(p)) return mp[p];
        bool rst = false;
        for(int i = 1; i <= maxInt; ++i) {
            if((bit & (1 << i)) == 0) {
                if(i >= desiredTotal) {
                    rst = true;
                } else if(!canWin(bit | (1 << i), desiredTotal - i)) {
                    rst = true;
                }
            }
        }
        // cout << "bit: ";
        // showBit(bit);
        // cout << " desiredTotal: " << desiredTotal;
        // cout << " rst: " << rst << endl;
        mp[p] = rst;
        return rst;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxInt = maxChoosableInteger;
        if( (maxInt * (maxInt - 1)) / 2 < desiredTotal) return false;
        return canWin(0, desiredTotal);
    }
};