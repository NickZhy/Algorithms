class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len <= 1) return len;
        vector<int> cd(len, 1);
        for(int i = 1; i < len; ++i) {
            if(ratings[i] > ratings[i - 1])
                cd[i] = max(cd[i], cd[i - 1] + 1);
        }
        for(int i = len - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1])
                cd[i] = max(cd[i], cd[i + 1] + 1);
        }
        int rst = 0;
        for(auto c: cd) {
//            cout << c << " ";
            rst += c;
        }
//        cout << endl;
        return rst;
    }
};