class Solution {
public:
    static bool cmp(string a, string b) {
        if(a.size() == b.size()) return a > b;
        return a.size() > b.size();
    }
    
    bool isSubSeq(string& a, string& b) {
        if(a.size() < b.size()) return false;
        int lenA = a.size(), lenB = b.size();
        vector<bool> dp(lenB + 1, false);
        dp[0] = true;
        for(int i = 1; i <= lenA; ++i)
            for(int j = lenB; j > 0; --j)
                if(a[i - 1] == b[j - 1])
                    dp[j] = dp[j - 1];
        return dp[lenB];
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        vector<string> scanned;
        int idx = 0;
        while(idx < strs.size()) {
            string& curr = strs[idx];
            int tmp = idx + 1;
            while(tmp < strs.size() && strs[tmp] == curr) ++tmp;
            if(tmp != idx + 1) {
                scanned.push_back(curr);
            } else {
                bool sign = true;
                for(string& s: scanned) {
                    if(isSubSeq(s, curr)) {
                        sign = false;
                        break;
                    }
                }
                if(sign) return curr.size();
            }
            idx = tmp;
        }
        return -1;
    }
};