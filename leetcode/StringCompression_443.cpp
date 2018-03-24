class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0, curr = 0;
        while(idx < chars.size()) {
            int num = 1;
            while(idx + num < chars.size() && chars[idx + num] == chars[idx]) ++num;
            chars[curr++] = chars[idx];
            if(num > 1) {
                for(char dig: to_string(num))
                    chars[curr++] = dig;
            }
            idx = idx + num;
        }
        return curr;
    }
};