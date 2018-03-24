class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size() <= 1) return 0;
        long sum = 0, F = 0;
        for(int i = 0; i < A.size(); ++i) {
            sum = sum + A[i];
            F = F + i * A[i];
        }
        long maxF = F;
        for(int i = A.size() - 1; i > 0; --i) {
            F = F - A.size() * A[i] + sum;
            maxF = max(F, maxF);
        }
        return maxF;
    }
};