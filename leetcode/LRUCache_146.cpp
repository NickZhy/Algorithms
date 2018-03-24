typedef pair<int, int> pr;
class LRUCache {
public:
    int max;
    int size;
    list<pr> q;
    unordered_map<int, list<pr>::iterator> key2Node;
    LRUCache(int capacity) {
        max = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(!key2Node.count(key)) return -1;
        pr t = *(key2Node[key]);
        q.erase(key2Node[key]);
        q.push_front(t);
        key2Node[key] = q.begin();
        return t.second;
    }
    
    void put(int key, int value) {
        if(!key2Node.count(key)) {
            if(size == max) {
                pr t = q.back();
                q.pop_back();
                key2Node.erase(t.first);
                --size;
            }
            q.push_front(pr(key, value));
            key2Node[key] = q.begin();
            ++size;
        } else {
            q.erase(key2Node[key]);
            q.push_front(pr(key, value));
            key2Node[key] = q.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */