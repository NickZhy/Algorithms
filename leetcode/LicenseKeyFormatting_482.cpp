class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        assert(K > 0);
        int len = S.size();
        string rst = "";
        for(int i = len - 1; i >= 0; --i) {
            if(S[i] != '-') {
                if(rst.size() % (K + 1) == K) rst += '-';
                rst += toupper(S[i]);
            }
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }
};