class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if(!len1 || !len2) return "0";
        
        vector<int> rst(len1 + len2, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < len1; ++i)
            for(int j = 0; j < len2; ++j)
                rst[i + j] += (num1[i] - '0') * (num2[j] - '0');
        
        int remain = 0;
        for(int i = 0; i < len1 + len2; ++i) {
            int t = rst[i] + remain;
            remain = t / 10;
            rst[i] = t % 10;
        }
        while(rst.size() > 1 && !rst.back()) rst.pop_back();
        string r = "";
        for(auto n: rst)
            r += n + '0';
        reverse(r.begin(), r.end());
        return r;
    }
};