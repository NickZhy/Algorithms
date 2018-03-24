class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        vector<int> stk;
        int stackBot = -1, stackTop = -1;
        int low = INT_MIN;
        for(int i = 0; i < preorder.size(); ++i) {
            if(preorder[i] < low)
                return false;
            while(stackTop > stackBot && preorder[stackTop] < preorder[i]) {
                low = preorder[stackTop--];
            }
            if(stackTop == stackBot) {
                stackBot = i - 1;
                stackTop = i;
            } else {
                stackTop++;
            }
        }
        return true;
    }
};