string wd1[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string wd2[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
                "Ninety"};

string wd3[] = {"Thousand", "Million", "Billion", "Trillion"};

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) 
            return wd1[0];
        string rst = "";
        int th = 0;
        while(num > 0) {
            int t = num % 100;
            if(t) {
                string sep = rst.size()? " ": "";
                if(t < 20)
                    rst = wd1[t] + sep + rst;
                else if(t % 10)
                    rst = wd2[t / 10] + " " + wd1[t % 10] + sep + rst;
                else
                    rst = wd2[t / 10] + sep + rst;
            }
            
            t = (num % 1000) / 100;
            if(t)
                rst = wd1[t] + " Hundred" + (rst.size()? " ": "") + rst;
            
            num /= 1000;
            if(num % 1000)
                rst = wd3[th] + (rst.size()? " ": "") + rst;
            th++;
        }
        return rst;
    }
};
