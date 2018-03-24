class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rst = (C - A) * (D - B) + (G - E) * (H - F);
        int x1 = max(A, E);
        int x2 = min(C, G);
        if(x2 <= x1) return rst;
        int y1 = max(B, F);
        int y2 = min(D, H);
        if(y2 <= y1) return rst;
        return rst - (y2 - y1) * (x2 - x1);
    }
};