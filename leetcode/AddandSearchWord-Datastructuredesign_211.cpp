class WordDictionary {
public:
    /** Initialize your data structure here. */
    class Node {
        public:
        bool hasChild;
        Node* child[26];
        Node(): child(), hasChild(false) {}
    };
    
    Node* root;
    
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* curr = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(!curr -> child[idx]) curr -> child[idx] = new Node();
            curr = curr -> child[idx];
        }
        curr -> hasChild = true;
    }
    
    bool searchFromNode(Node* root, string word) {
        if(!word.size()) return root -> hasChild;
        if(word[0] == '.') {
            for(int i = 0; i < 26; ++i)
                if(root -> child[i] && searchFromNode(root -> child[i], word.substr(1))) 
                    return true;
            return false;
        }
        int idx = word[0] - 'a';
        if(!root -> child[idx]) return false;
        return searchFromNode(root -> child[idx], word.substr(1));
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchFromNode(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */