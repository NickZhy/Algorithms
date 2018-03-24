class Solution {
public:
    bool startWith(string a, string b) {
        if(a.size() > b.size()) return false;
        return b.substr(0, a.size()) == a;
    }
    
    bool helper(string& pattern, int idx1,  
                string& str, int idx2, 
                unordered_map<string, char> s2p,
                unordered_map<char, string> p2s) {
        if(idx1 == pattern.size() && idx2 == str.size()) return true;
        char p = pattern[idx1];
        if(p2s.count(p) > 0) {
            if(!startWith(p2s[p], str.substr(idx2))) return false;
            return helper(pattern, idx1 + 1, str, idx2 + p2s[p].size(), s2p, p2s);
        } else {
            for(int i = 1; idx2 + i <= str.size(); ++i) {
                string curr = str.substr(idx2, i);
                if(s2p.count(curr) == 0) {
                    s2p[curr] = p;
                    p2s[p] = curr;
                    bool match = helper(pattern, idx1 + 1, str, idx2 + curr.size(), s2p, p2s);
                    if(match) return true;
                    s2p.erase(curr);
                    p2s.erase(p);
                }
            }
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<string, char> s2p;
        unordered_map<char, string> p2s;
        return helper(pattern, 0, str, 0, s2p, p2s);
    }
};