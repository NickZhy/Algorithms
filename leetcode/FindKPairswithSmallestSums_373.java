class Solution {
    int[] n1;
    int[] n2;
    class PairComparator implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return (n1[a[0]] + n2[a[1]]) - (n1[b[0]] + n2[b[1]]);
        }
    }
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        if(nums1.length == 0 || nums2.length == 0) 
            return new ArrayList<int[]>();
        n1 = nums1;
        n2 = nums2;
        Queue<int[]> q = new PriorityQueue<int[]>(nums1.length, new PairComparator());
        for(int i = 0; i < nums1.length && i < k; ++i)
            q.add(new int[]{i, 0});
        
        List<int[]> rst = new ArrayList<int[]>();
        while(q.size() > 0 && k-- > 0) {
            int[] t = q.poll();
            if(t[1] + 1 < nums2.length)
                q.add(new int[]{t[0], t[1] + 1});
            rst.add(new int[]{nums1[t[0]], nums2[t[1]]});
        }
        return rst;
    }
}