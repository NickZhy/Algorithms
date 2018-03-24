class Solution {
    int perm(int n) {
        if(n <= 1) return 1;
        return n * perm(n - 1);
    }
    
    int findNth(boolean[] nums, int rank) {
        int c = -1;
        for(int i = 1; i < nums.length; ++i) {
            if(!nums[i]) {
                ++c;
                if(c == rank) return i;
            }
        }
        return -1;
    }
    
    public String getPermutation(int n, int k) {
        boolean nums[] = new boolean[n + 1];
        String rst = "";
        --k;
        for(int i = n - 1; i >= 0; --i) {
            int permN = perm(i);
            int digit = findNth(nums, k / permN);
            k %= permN;
            rst += digit;
            nums[digit] = true;
        }
        return rst;
    }
}