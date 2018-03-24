class Solution {
public:
    string addBinary(string a, string b) {
        string rst = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int idx = 0;
        int remains = 0;
        while(idx < a.size() || idx < b.size()) {
            int aBit = idx < a.size()? a[idx] - '0': 0;
            int bBit = idx < b.size()? b[idx] - '0': 0;
            int tmp = aBit + bBit + remains;
            rst += (tmp % 2 + '0');
            remains = tmp / 2;
            ++idx;
        }
        if(remains) rst += '1';
        while(rst.size() > 1 && rst.back() == '0') rst.pop_back();
        reverse(rst.begin(), rst.end());
        return rst;
    }
};