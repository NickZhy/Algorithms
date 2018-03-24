class Solution {
    vector<vector<vector<int>>> mem;
    int readNum(string& str, int& idx) {
        int c = 0;
        while(idx < str.size() && isdigit(str[idx])) 
            c = c * 10 + str[idx++] - '0';
        return c;
    }
    
    int compute(char sign, int num1, int num2) {
        switch(sign) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            default: assert(false);
        }
        return -1;
    }
    
    void dfs(int i, int j, vector<int>& num, vector<char>& sign) {
        if(mem[i][j].size() || j < i) return;
        if(i == j) {
            mem[i][j] = { compute(sign[i], num[i], num[i + 1]) };
            return;
        }
        for(int s = i + 1; s < j;++s) {
            dfs(i, s - 1, num, sign);
            dfs(s + 1, j, num, sign);
            for(int n1: mem[i][s - 1])
                for(int n2: mem[s + 1][j])
                    mem[i][j].push_back(compute(sign[s], n1, n2));
        }
        
        dfs(i, j - 1, num, sign);
        for(int n1: mem[i][j - 1])
            mem[i][j].push_back(compute(sign[j], n1, num[j + 1]));
        
        dfs(i + 1, j, num, sign);
        for(int n2: mem[i + 1][j])
            mem[i][j].push_back(compute(sign[i], num[i], n2));

    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> signs;
        int idx = 0;
        while(idx < input.size()) {
            nums.push_back(readNum(input, idx));
            if(idx < input.size())
                signs.push_back(input[idx++]);
        }
        int len = signs.size();
        if(len == 0) 
            return { nums[0] };
        mem.resize(len);
        for(vector<vector<int>>& m: mem)
            m.resize(len);
        dfs(0, len - 1, nums, signs);
        return mem[0][len - 1];
    }
};