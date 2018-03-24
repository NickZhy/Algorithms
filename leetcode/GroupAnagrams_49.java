class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mp = new HashMap<String, List<String>>();
        for(String s: strs) {
            char[] tmp = s.toCharArray();
            Arrays.sort(tmp);
            String st = new String(tmp);
            if(mp.get(st) == null)
                mp.put(st, new ArrayList<String>());
            mp.get(st).add(s);
        }
        List<List<String>> rst = new ArrayList<List<String>>();
        for(List<String> r : mp.values()) 
            rst.add(new ArrayList<String>(r));
        return rst;
    }
}