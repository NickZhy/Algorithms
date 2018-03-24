class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int rstLen = 1 << len;
        vector<vector<int> > rst(rstLen);
        rst[0] = vector<int>();
        int currLen = 1;
        for(int i = 0; i < len; ++i) {
            cout << "currLen:" << currLen << endl;
            for(int j = 0; j < currLen; ++j) {
                cout << "j:" << j << endl;
                rst[currLen + j] = rst[j];
                rst[currLen + j].push_back(nums[i]);
                cout << "over" << endl;
            }
            currLen = currLen * 2;
        }
        cout << "?" << endl;
        return rst;
    }
};