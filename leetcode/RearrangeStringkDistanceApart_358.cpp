class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
    string rearrangeString(string s, int k) {
        int len = s.size();
        if(len <= 1 || k <= 1) return s;
        int count[26] = { 0 };
        for(char ch: s) ++count[ch - 'a'];
        
        string rst = "";
        set<char> banned;
        while(rst.size() < len) {
            int maxCount = 0, maxIdx = -1;
            for(int i = 0; i < 26; ++i)
                if(!banned.count('a' + i) && count[i] > maxCount) {
                    maxCount = count[i];
                    maxIdx = i;
                }
            if(maxIdx == -1) return "";
            rst += 'a' + maxIdx;
            --count[maxIdx];
            banned.insert('a' + maxIdx);
            if(rst.size() >= k) banned.erase(rst[rst.size() - k]);
        }
        return rst;
    }
};