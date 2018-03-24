typedef pair<int, int> pr;
class Solution {
public:
 	static bool cmp (pr a, pr b) {
        return a.first > b.first;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<pr> hp;
        vector<int> rst(len, 0);
        for(int i = 0; i < len; ++i) {
            while(hp.size() && hp.front().first < temperatures[i]) {
                pop_heap(hp.begin(), hp.end(), cmp);
                pr tmp = hp.back();
                rst[tmp.second] = i - tmp.second;
                hp.pop_back();
            }
            hp.push_back(pr(temperatures[i], i));
            push_heap(hp.begin(), hp.end(), cmp);
        }
        return rst;
    }

};