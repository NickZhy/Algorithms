class Solution {
public:
    vector<string> helper(int n, bool hasZero) {
        if(n == 0) return {};
        if(n == 1) return {"0", "1", "8"};
        vector<string> rst2;
        if(hasZero)
            rst2 = {"00", "11", "69", "88", "96"};
        else
            rst2 = {"11", "69", "88", "96"};
        if(n == 2) return rst2;
        vector<string> tmp = helper(n - 2, true);
        vector<string> rst;
        for(string r: rst2)
            for(string t: tmp) 
                rst.push_back(r[0] + t + r[1]);
        return rst;
    }
    vector<string> findStrobogrammatic(int n) {
        return helper(n, false);
    }
};