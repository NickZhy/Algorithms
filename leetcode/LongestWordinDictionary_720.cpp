class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> s;
        string rst = "";
        for(string& wd: words) {
            if(wd.size() == 1 || s.count(wd.substr(0, wd.size() - 1))) {
                s.insert(wd);
                if(wd.size() > rst.size())
                    rst = wd;
            }
        }
        return rst;
    }
};