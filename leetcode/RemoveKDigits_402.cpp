class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        string rst = "";
        for(int i = 0; i < len; ++i) {
            while(k > 0 && rst.size() && rst.back() > num[i]) {
                rst.pop_back();
                --k;
            }
            rst.push_back(num[i]);
        }
        
        while(k > 0 && rst.size()) {
            rst.pop_back();
            --k;
        }
        
        if(!rst.size()) return "0";
        
        int i = 0;
        while(i < rst.size() - 1 && rst[i] == '0') ++i;
        return rst.substr(i);
    }
};