class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashSet<String> rst = new HashSet<String>();
        if(s.length() < 10) return new ArrayList<String>();
        
        int pos = 10;
        String curr = s.substring(0, 10);
        HashSet<String> find = new HashSet<String>();
        find.add(curr);
        while(pos < s.length()) {
            curr = curr.substring(1);
            curr += s.charAt(pos++);
            if(find.contains(curr)) {
                rst.add(curr);
            } else {
                find.add(curr);
            }
        }
        return new ArrayList<String>(rst);
    }
}