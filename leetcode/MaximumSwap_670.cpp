class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        for(int i = 0; i < str.size() - 1; ++i) {
            char maxVal = 0;
            int maxPos = -1;
            for(int j = i + 1; j < str.size(); ++j) {
                if(str[j] >= maxVal) {
                    maxVal = str[j];
                    maxPos = j;
                }
            }
            if(maxPos != -1 && maxVal > str[i]) {
                swap(str[i], str[maxPos]);
                break;
            }
        }
        return stoi(str);
    }
};