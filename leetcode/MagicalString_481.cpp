class Solution {
public:
    int magicalString(int n) {
        string str = "122";
        int idx = 2;
        while(str.size() < n) {
            if(str[idx++] == '1') {
                str += (str.back() == '1'? "2": "1");
            } else {
                str += (str.back() == '1'? "22": "11");
            }
        }
        int rst = 0;
        for(int i = 0; i < n; ++i)
            rst += (str[i] == '1');
        return rst;
    }
};