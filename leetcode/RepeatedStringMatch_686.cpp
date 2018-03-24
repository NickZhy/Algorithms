class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i = 0; i < A.size(); ++i) {
            bool sign = true;
            for(int j = 0; j < B.size() && sign; ++j) {
                int k = (i + j) % A.size();
                sign = (B[j] == A[k]);
            }
            if(sign) 
                return (i + B.size()) / A.size() + ((i + B.size()) % A.size() != 0);
        }
        return -1;
    }
};