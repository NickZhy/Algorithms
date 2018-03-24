class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, 
                                       {'X', 10}, {'L', 50}, 
                                       {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        reverse(s.begin(), s.end());
        int rst = 0;
        int idx = 0;
        for(int i = 0; i < s.size(); ++i) {
            rst += mp[s[i]];
            if(i + 1 < s.size() && mp[s[i + 1]] < mp[s[i]]) rst -= mp[s[++i]];
        }
        return rst;
    }
};