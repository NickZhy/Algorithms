class Solution {
public:
    string strAdd(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string rst = "";
        int remain = 0;
        for(int i = 0; i < max(a.size(), b.size()); ++i) {
            int t1 = 0, t2 = 0;
            if(i < a.size()) t1 = a[i] - '0';
            if(i < b.size()) t2 = b[i] - '0';
            int tmp = t1 + t2 + remain;
            rst += ('0' + tmp % 10);
            remain = tmp / 10;
        }
        if(remain > 0) rst += ('0' + remain);
        reverse(rst.begin(), rst.end());
        return rst;
    }
    bool helper(string a, string b, string num) {
        //cout << a << "," << b << "," << num << endl;
        if(num.size() == 0) return true;
        string c = strAdd(a, b);
        if(c.size() > num.size()) return false;
        if(num.substr(0, c.size()) == c)
            return helper(b, c, num.substr(c.size()));
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;
        for(int i = 1; i <= num.size() / 2; ++i) {
            string a = num.substr(0, i);
            for(int j = 1; max(i, j) <= num.size() - i - j; ++j) {
                string b = num.substr(i, j);
                if(helper(a, b, num.substr(i + j))) return true;
                if(num[i] == '0') break;
            }
        }
        return false;
    }
};