class Solution {
    class Node {
        boolean hasWord = false;
        Node child[] = new Node[26];
    }
    Node root = new Node();
    void addWord(String word) {
        Node curr = root;
        for(char ch: word.toCharArray()) {
            int idx = ch - 'a';
            if(curr.child[idx] == null)
                curr.child[idx] = new Node();
            curr = curr.child[idx];
        }
        curr.hasWord = true;
    }
    String searchPrefix(String word) {
        Node curr = root;
        String rst = "";
        for(char ch: word.toCharArray()) {
            int idx = ch - 'a';
            if(curr.child[idx] == null) return word;
            curr = curr.child[idx];
            rst += ch;
            if(curr.hasWord) return rst;
        }
        return word;
    }
    public String replaceWords(List<String> dict, String sentence) {
        if(sentence.length() == 0) return "";
        for(String wd: dict)
            addWord(wd);
        String rst = "";
        for(String wd: sentence.split(" "))
            rst += searchPrefix(wd) + " ";
        if(rst.length() == 0) return "";
        return rst.substring(0, rst.length() - 1);
    }
}