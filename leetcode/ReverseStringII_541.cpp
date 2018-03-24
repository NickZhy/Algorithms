class Solution {
public:
    void revStr(string& s, int i, int j) {
        while(i < j) swap(s[i++], s[j--]);
    }
    string reverseStr(string s, int k) {
        if(k <= 1) return s;
        string rst = s;
        int start = 0, len = rst.size();
        while(start < len) {
            revStr(rst, start, min(start + k - 1, len - 1));
            start += 2 * k;
        }
        return rst;
    }
};