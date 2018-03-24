class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(!len) return;
        vector<int>::iterator mid = nums.begin() + len / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        
        int i = 0, j = 0, k = 0;
        #define A(m) nums[(1 + 2 * m) % (len | 1)]
        while(k < len) {
            if(A(k) > median) {
                swap(A(k), A(j));
                swap(A(j++), A(i++));
            } else if(A(k) == median) {
                swap(A(k), A(j++));
            }
            ++k;
        }
        
    }
};