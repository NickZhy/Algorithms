class Solution {
    class Pair implements Comparable<Pair>{
        String word;
        int freq;
        Pair(String wd, int f) {
            freq = f;
            word = wd;
        }
        public int compareTo(Pair b) {
            if(freq == b.freq) return -word.compareTo(b.word);
            return freq - b.freq;
        }
    }
    
    public List<String> topKFrequent(String[] words, int k) {
        Queue<Pair> que = new PriorityQueue<Pair>();
        HashMap<String, Integer> mp = new HashMap<String, Integer>();
        for(String wd: words) {
            if(mp.get(wd) == null) mp.put(wd, 0);
            mp.put(wd, mp.get(wd) + 1);
        }
        for(String key :mp.keySet()) {
            Pair tmp = new Pair(key, mp.get(key));
            if(que.size() < k) {
                que.add(tmp);
            } else if(que.peek().compareTo(tmp) < 0) {
                que.poll();
                que.add(tmp);
            }
        }
        List<String> rst = new ArrayList<String>();
        while(!que.isEmpty())
            rst.add(que.poll().word);
        Collections.reverse(rst);
        return rst;
    }
}