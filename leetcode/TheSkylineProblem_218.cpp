class Solution {
public:
    class Comp{
        public:
        bool operator()(vector<int> a, vector<int> b) {
            return a[1] > b[1];
        }
    };
    
    void tryInsert(vector<pair<int, int>>& rst, pair<int, int> pos) {
        if(!rst.size()) {
            rst.push_back(pos);
        } else if(rst.back().first == pos.first){
            rst.back().second = pos.second;
        } else if(rst.back().second != pos.second){
            rst.push_back(pos);
        }
    }
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int> mpHei;
        ++mpHei[0];
        priority_queue<vector<int>, vector<vector<int>>, Comp> hp;
        vector<pair<int, int>> rst;
        for(vector<int>& bd: buildings) {
            while(hp.size() && hp.top()[1] < bd[0]) {
                vector<int> tmp = hp.top();
                hp.pop();
                if(--mpHei[tmp[2]] == 0) {
                    mpHei.erase(tmp[2]);
                    int currHei = mpHei.rbegin() -> first;
                    tryInsert(rst, pair<int, int>(tmp[1], currHei));
                }
            }
            ++mpHei[bd[2]];
            hp.push(bd);
            int currHei = mpHei.rbegin() -> first;
            tryInsert(rst, pair<int, int>(bd[0], currHei));
        }
        while(hp.size()) {
            vector<int> tmp = hp.top();
            hp.pop();
            if(--mpHei[tmp[2]] == 0) {
                mpHei.erase(tmp[2]);
                int currHei = mpHei.rbegin() -> first;
                tryInsert(rst, pair<int, int>(tmp[1], currHei));
            }
        }
        return rst;
    }
};