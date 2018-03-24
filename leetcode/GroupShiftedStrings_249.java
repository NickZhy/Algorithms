class Solution {
    String shiftLeft(String s) {
        int shift = s.charAt(0) - 'a';
        String rst = "";
        for(char ch: s.toCharArray()) {
            int dist = ch - 'a';
            rst += 'a' + (dist + 26 - shift) % 26;
        }
        return rst;
    }
    public List<List<String>> groupStrings(String[] strings) {
        HashMap<String, List<String>> rst= new HashMap<String, List<String>>();
        for(String s: strings) {
            String sl = shiftLeft(s);
            if(rst.get(sl) == null) 
                rst.put(sl, new ArrayList<String>());
            rst.get(sl).add(s);
        }
        return new ArrayList<List<String>>(rst.values());
    }
}