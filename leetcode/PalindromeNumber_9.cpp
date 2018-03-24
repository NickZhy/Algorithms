class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0) return false;
       long t = 0;
       int remain = x;
       while(remain) {
           t *= 10;
           t += (remain % 10);
           remain /= 10;
       }
       return x == t;
    }
};