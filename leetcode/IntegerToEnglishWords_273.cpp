class Solution {
    vector<string> tb1 = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", 
                          "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", 
                          "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string> tb2 = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    vector<string> tb3 = {"", "Thousand ", "Million ", "Billion "};
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<int> segs;
        while(num) {
            segs.push_back(num % 1000);
            num /= 1000;
        }
        string rst = "";
        for(int i = segs.size() - 1; i >= 0; --i) {
            int tmp = segs[i];
            if(tmp >= 100) 
                rst += tb1[tmp / 100] + "Hundred ";
            tmp %= 100;
            if(tmp < 20) {
                rst += tb1[tmp];
            } else {
                rst += tb2[tmp / 10] + tb1[tmp % 10];
            }
            if(segs[i] != 0)
                rst += tb3[i];
        }
        rst.pop_back();
        return rst;
    }
};