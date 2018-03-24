class Solution {
    class Node {
        boolean hasWord = false;
        Node[] child = new Node[26];
    }
    
    void addWord(Node root, String wd) {
        Node curr = root;
        for(char ch: wd.toCharArray()) {
            int idx = ch - 'a';
            if(curr.child[idx] == null) curr.child[idx] = new Node();
            curr = curr.child[idx];
        }
        curr.hasWord = true;
    }
    
    void findHelper(Node root, String curr, List<String> rst) {
        if(root == null) return;
        if(root.hasWord) rst.add(curr);
        for(int i = 0; i < 26; ++i) {
            if(root.child[i] != null) {
                curr += (char)('a' + i);
                findHelper(root.child[i], curr, rst);
                curr = curr.substring(0, curr.length() - 1);
            }
        }
    }
    
    List<String> findWord(Node root) {
        List<String> rst = new ArrayList<String>();
        String curr = "";
        findHelper(root, curr, rst);
        return rst;
    }
    
    List<String> startWith(Node root, String str) {
        if(root == null) return new ArrayList<String>();
        Node curr = root;
        for(char ch: str.toCharArray()) {
            curr = curr.child[ch - 'a'];
            if(curr == null) return new ArrayList<String>();
        }
        List<String> rst = findWord(curr);
        return rst;
    }
    
    void dfs(int next, int len, Node root, List<String> curr, List<List<String>> rst) {
        if(next == len) {
            rst.add(new ArrayList<String>(curr));
            return;
        }
        
        String head = "";
        for(int i = 0; i < next; ++i) head += curr.get(i).charAt(next);
        
        List<String> tails = startWith(root, head);
        for(String t: tails) {
            String str = head + t;
            curr.add(str);
            dfs(next + 1, len, root, curr, rst);
            curr.remove(next);
        }
    }
    
    public List<List<String>> wordSquares(String[] words) {
        List<List<String>> rst = new ArrayList<List<String>>();
        if(words.length == 0) return rst;
        int len = words[0].length();
        List<String> curr = new ArrayList<String>();
        Node root = new Node();
        for(String wd: words) addWord(root, wd);
        dfs(0, len, root, curr, rst);
        return rst;
    }
}