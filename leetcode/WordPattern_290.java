class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] wd = str.split(" ");
        if(wd.length != pattern.length()) return false;
        String[] hist = new String[26];
        HashMap<String, Integer> mp = new HashMap<String, Integer>();
        for(int i = 0; i < pattern.length(); ++i) {
            int idx = pattern.charAt(i) - 'a';
            if(hist[idx] == null && mp.get(wd[i]) == null) {
                hist[idx] = wd[i];
                mp.put(wd[i], idx);
            }
            if(hist[idx] != null && !hist[idx].equals(wd[i]))
                return false;
            if(mp.get(wd[i]) != null && mp.get(wd[i]) != idx)
                return false;
        }
        return true;
    }
}