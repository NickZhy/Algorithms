class LRUCache {
    class node {
        public:
            int key;
            int value;
            node* prev;
            node* next;
        node(int k, int v, node* pv, node* nt) {
            key = k;
            value = v;
            prev = pv;
            next = nt;
        }
    };
    
    int max;
    int num;
    node* head;
    node* tail;
    unordered_map<int, node*> mp;
public:
    LRUCache(int capacity) {
        max = capacity;
        num = 0;
        head = tail = NULL;
    }
    
    node* getNode(int key) {
        if (mp.find(key) != mp.end()) {
            node *p = mp[key];
            if(p -> prev) {
                p -> prev -> next = p -> next;
                if(p -> next)
                    p -> next -> prev = p -> prev;
                else
                    tail = p -> prev;
                head -> prev = p;
                p -> next = head;
                p -> prev = NULL;
                head = p;
            }
            return mp[key];
        }
        return NULL;
    }
    
    int get(int key) {
        node* p = getNode(key);
        if(p)
            return p -> value;
        return -1;
    }
    
    void put(int key, int value) {
        if(max == 0) return;
        node* p = getNode(key);
        if(p) {
            p -> value = value;
            return;
        }
        
        p = new node(key, value, NULL, head);
        mp[key] = p;
        if(head) 
            head -> prev = p;
        else
            tail = p;
        head = p;
        if(num == max) {
            mp.erase(tail -> key);
            tail = tail -> prev;
            delete tail -> next;
            tail -> next = NULL;
        } else {
            ++num;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
