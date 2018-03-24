class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> rst = new ArrayList<Integer>();
        rst.add(0);
        for(int i = 0; i < n; ++i) {
            int t = rst.size() - 1;
            while(t >= 0) rst.add(rst.get(t--) | (1 << i));
        }
        return rst;
    }
}