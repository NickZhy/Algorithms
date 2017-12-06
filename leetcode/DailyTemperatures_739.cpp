typedef pair<int, int> pr;
class Solution {
public:
 	static bool cmp (pr a, pr b) {
        return a.first > b.first;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<pr> stk;
        vector<int> rst(len, 0);
        for(int i = 0; i < len; ++i) {
            while(stk.size() && stk.back().first < temperatures[i]) {
                pr tmp = stk.back();
                rst[tmp.second] = i - tmp.second;
                stk.pop_back();
            }
            stk.push_back(pr(temperatures[i], i));
        }
        return rst;
    }
};
