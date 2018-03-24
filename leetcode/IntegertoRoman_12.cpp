class Solution {
public:
    string intToRoman(int num) {
        string tb1 = "IXCM";
        string tb2 = "VLD";
        string rst = "";
        int idx = 0;
        while(num > 0) {
            int tmp = num % 10;
            num /= 10;
            if(tmp % 5 < 4) {
                for(int i = 0; i < tmp % 5; ++i) 
                    rst += tb1[idx];
                if(5 <= tmp) rst += tb2[idx];
            } else {
                rst += tmp > 5 ? tb1[idx + 1]: tb2[idx];
                for(int i = 0; i < 5 - tmp % 5; ++i) 
                    rst += tb1[idx];
            }
            ++idx;
        }
        reverse(rst.begin(), rst.end());
        return rst;   
    }
};