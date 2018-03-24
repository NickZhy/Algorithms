class Solution {
public:
    string i2TimeStr(int num) {
        return (num < 10? "0": "") + to_string(num);
    }
    string nextClosestTime(string time) {
        set<int> digits;
        for(char ch: time)
            if(ch != ':') digits.insert(ch - '0');
        
        string hhStr = time.substr(0, 2);
        string mmStr = time.substr(3, 2);
        
        int mm = stoi(mmStr);
        for(int i = mm + 1; i < 60; ++i) {
            if(digits.count(i % 10) && digits.count(i / 10))
                return hhStr + ":" + i2TimeStr(i);
        }
        
        int hh = stoi(hhStr);
        for(int i = 1; i <= 24; ++i) {
            int tmp = (hh + i) % 24;
            if(digits.count(tmp % 10) && digits.count(tmp / 10)) {
                int mmMin = *digits.begin(); // it must be smaller than 
                mmMin = mmMin * 10 + mmMin;
                return i2TimeStr(tmp) + ":" + i2TimeStr(mmMin);
            }
        }
        return time;
    }
};