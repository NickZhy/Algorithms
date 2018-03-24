class Solution {
public:
    int gcd(int a, int b) {
        if(a > b) swap(a, b);
        if(a == 0 || b % a == 0) return a;
        return gcd(b % a, a);
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(!len) return;
        k %= len;
        int g = gcd(len, k);
        for(int i = 0; i < g; ++i) {
            int tmp = nums[i];
            int curr = i;
            do {
                curr = (curr + k) % len;
                swap(tmp, nums[curr]);
            } while(curr != i);
        }
    }
};