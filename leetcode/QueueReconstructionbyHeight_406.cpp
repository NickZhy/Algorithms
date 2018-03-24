class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int>> rst;
        for(auto& p: people)
            rst.insert(rst.begin() + p.second, p);
        return rst;
    }
};