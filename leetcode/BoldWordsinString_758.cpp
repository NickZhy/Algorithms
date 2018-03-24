class Solution {
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
public:
    string boldWords(vector<string>& words, string S) {
        vector<pair<int, int>> pos;
        for(string& wd: words) 
            for(int i = 0; i <= S.size() - wd.size(); ++i) {
                if(S.substr(i, wd.size()) == wd)
                    pos.push_back(pair<int, int>(i, i + wd.size()));
            }
        
        if(!pos.size()) return S;
        
        sort(pos.begin(), pos.end(), cmp);
        string rst;
        int idx = 0, end = -1;
        for(int i = 0; i < pos.size(); ++i) {
            if(pos[i].first > end) {
                if(end != -1) rst += "</b>";
                while(idx < pos[i].first)
                    rst += S[idx++];
                rst += "<b>";
            }
            end = max(end, pos[i].second);
            while(idx < end)
                rst += S[idx++];
        }
        rst += "</b>";
        while(idx < S.size())
            rst += S[idx++];
        return rst;
    }
};