class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return;
        auto mid = nums.begin() + len / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        #define A(n) nums[(1 + 2 * n) % (len | 1)]
        int i = 0, j = 0, k = 0;
        while(k < len) {
            if(A(k) > median) {
                swap(A(j), A(k));
                swap(A(i++), A(j++));
            } else if(A(k) == median) {
                swap(A(j++), A(k));
            }
            ++k;
        }
    }
};