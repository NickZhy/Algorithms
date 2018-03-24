class Solution {
public:
    unordered_map<string, vector<string> > al;
    vector<string> possible(string bottom) {
        int len = bottom.size();
        if(len == 2) return al[bottom];
        if(!al[bottom.substr(len - 2, 2)].size()) return vector<string>();
        vector<string> poss = possible(bottom.substr(0, len - 1));
		vector<string> rst;
        for(auto tail: al[bottom.substr(len - 2, 2)]) {
            vector<string> tmp = poss;
            for(auto& t: tmp) t += tail;
            rst.insert(rst.end(), tmp.begin(), tmp.end());
        }
        return rst;
    }
    bool helper(string bottom) {
        if(bottom.size() == 2) return possible(bottom).size();
        vector<string> ps = possible(bottom);
        for(auto s: ps)
            if(helper(s)) return true;
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom.size() < 2) return false;
        for(auto s: allowed)
            al[s.substr(0, 2)].push_back(s.substr(2, 1));
        return helper(bottom);
    }
};
