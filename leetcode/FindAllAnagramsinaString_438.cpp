class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int start = 0, end = 0;
        int remains = p.size();
        int count[255] = {0};
        for(char ch: p)
            ++count[ch];
        vector<int> rst;
        while(end < s.size()) {
            while(end < s.size() && remains > 0) {
                char ch = s[end++];
                --count[ch];
                --remains;
                while(count[ch] < 0) {
                    ++count[s[start++]];
                    ++remains;
                }
            }
            if(remains == 0) {
                rst.push_back(start);
                ++count[s[start++]];
                ++remains;
            }
        }
        return rst;
    }
};