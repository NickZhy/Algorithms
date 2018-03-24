class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if(!len1 || !len2) return !len1? num2: num1;
        string rst;
        int idx1 = len1 - 1, idx2 = len2 - 1;
        int remains = 0;
        while(idx1 >= 0 || idx2 >= 0) {
            int a = idx1 >= 0? num1[idx1--] - '0': 0;
            int b = idx2 >= 0? num2[idx2--] - '0': 0;
            int tmp = a + b + remains;
            rst.push_back('0' + tmp % 10);
            remains = tmp / 10;
        }
        if(remains) rst.push_back('1');
        reverse(rst.begin(), rst.end());
        return rst;
    }
};