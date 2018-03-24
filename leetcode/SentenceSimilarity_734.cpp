class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> prs;
        for(auto p: pairs) {
            prs[p.first].insert(p.second);
            prs[p.second].insert(p.first);
        }
        for(int i = 0; i < words1.size(); ++i)
            if(words1[i] != words2[i] && !prs[words1[i]].count(words2[i])) return false;
        return true;
    }
};