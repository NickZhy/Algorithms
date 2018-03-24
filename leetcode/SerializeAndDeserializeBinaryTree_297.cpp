/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*,int> entry;
class Codec {
public:
    string dumpPair(entry ety) {
        return "(" + to_string(ety.first -> val) + "," + to_string(ety.second) + ")";
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        
        string rst = "";
        queue<entry> que;

        int count = 1;
        que.push(entry(root,0));
        while (que.size()) {
            entry tEty = que.front();
            que.pop();
            rst += dumpPair(tEty);
            TreeNode* node = tEty.first;
            if(node->left) {
                que.push(entry(node->left, -count));
            }
            if(node->right) {
                que.push(entry(node->right, count));
            }
            ++count;
        }
        return rst;
    }

    int readInt(string &data, int &pos) {
        bool sign = true;
        int num = 0;
        if (data[pos] == '-') {
            sign = false;
            ++pos;
        }
        while (data[pos] >= '0' && data[pos] <= '9') {
            num *= 10;
            num += data[pos++] - '0';
        }
        return sign ? num: -num;
    }
    
    pair<int, int> readPair(string &data, int &pos) {
        pair<int, int> rst;
        ++pos;  // read (
        rst.first = readInt(data, pos);      
        ++pos;  // read ,
        rst.second = readInt(data, pos);
        ++pos;  // read )
        return rst;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size()) {
            return NULL;
        }
        int pos = 0;
        map<int,TreeNode*> mp;
        
        int num = 1;
        while (pos < data.size()) {
            pair<int, int> ety = readPair(data, pos);
            TreeNode* node = new TreeNode(ety.first);
            mp[num++] = node;
            if(ety.second == 0) continue; // root node;
            TreeNode* father = mp[abs(ety.second)];
            if(ety.second < 0){
                father->left = node;
            } else {
                father->right = node;
            }
            
        }
        return mp[1];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));