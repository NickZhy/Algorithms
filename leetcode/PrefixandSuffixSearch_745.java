class WordFilter {
    class Node {
        int weight = -1;
        Node child[] = new Node[26];
    }
    
    Node root = new Node();
    
    void addWord(String wd, int weight) {
        Node curr = root;
        for(char ch: wd.toCharArray()) {
            int idx = ch - 'a';
            if(curr.child[idx] == null) 
                curr.child[idx] = new Node();
            curr = curr.child[idx];
        }
        curr.weight = weight;
    }
    
    public WordFilter(String[] words) {
        for(int i = 0; i < words.length; ++i)
            addWord(words[i], i);
    }
    
    class Pair {
        String str = "";
        int weight = 0;
        Pair(String s, int w) {
            str = s;
            weight = w;
        }
    }
    
    void dfs(Node root, String curr, List<Pair> rst) {
        if(root.weight != -1)
            rst.add(new Pair(curr, root.weight));
        
        for(int i = 0; i < 26; ++i) {
            if(root.child[i] != null) {
                curr += (char)(i + 'a');
                dfs(root.child[i], curr, rst);
                curr = curr.substring(0, curr.length() - 1);
            }
        }
    }
    
    public int f(String prefix, String suffix) {
        Node curr = root;
        for(char ch: prefix.toCharArray()) {
            int idx = ch - 'a';
            if(curr.child[idx] == null) return -1;
            curr = curr.child[idx];
        }
        List<Pair> tails = new ArrayList<Pair>();
        String tmp = "";
        dfs(curr, tmp, tails);
        int maxWeight = -1;
        for(Pair p: tails) {
            tmp = prefix + p.str;
            if(tmp.endsWith(suffix))
                maxWeight = Math.max(maxWeight, p.weight);
        }
        return maxWeight;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */