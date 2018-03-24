class Trie {
public:
    /** Initialize your data structure here. */
    class Node {
        public:
        bool hasChild;
        Node* child[26];
        Node(): child(), hasChild(false) {}
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(!curr -> child[idx]) curr -> child[idx] = new Node();
            curr = curr -> child[idx];
        }
        curr -> hasChild = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(!curr -> child[idx]) return false;
            curr = curr -> child[idx];
        }
        return curr -> hasChild;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch: prefix) {
            int idx = ch - 'a';
            if(!curr -> child[idx]) return false;
            curr = curr -> child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */