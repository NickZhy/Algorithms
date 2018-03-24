class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> mp;
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';
        
        string rst;
        for(int i = 0; i < num.size(); ++i) {
            char ch = num[i];
            if(!mp.count(ch)) return false;
            rst.push_back(mp[ch]);
        }
        cout << rst << endl;
        reverse(rst.begin(), rst.end());
        return rst == num;
    }
};