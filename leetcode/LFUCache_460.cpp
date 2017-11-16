/*
 first -> {frequency, list} -> {frequency, list} -> {frequency, list}
                        |                    |                    |
                        V                    V                    V
                      first                first                first
                        |                    |                    |
                        V                    V                    V
                      {val}                {val}                {val}
                        |                    |
                        V                    V
                      {val}                {val}

*/
class LinkedNode {
    public:
    LinkedNode* prev;
    LinkedNode* next;
    LinkedNode() {
        prev = NULL;
        next = NULL;
    }
};

class VNode: public LinkedNode {
    public:
    int key;
    int val;
    LinkedNode* head;
    VNode(int k, int v, LinkedNode* h) {
        key = k;
        val = v;
        head = h;
    }
};

class FNode: public LinkedNode {
    public:
    int freq;
    LinkedNode* head;
    LinkedNode* tail;
    FNode(int f) {
        freq = f;
        tail = head = new LinkedNode();
    }
    ~FNode() {
        delete head;
    }
};

void insertNext(LinkedNode* p, LinkedNode* n, LinkedNode* &tail) {
    n->next = p->next;
    n->prev = p;
    p->next = n;
    if(n->next)
        n->next->prev = n;
    if(p == tail)
        tail = n;
}

void removeNode(LinkedNode* p, LinkedNode* &tail) {
    p->prev->next = p->next;
    if(p->next)
        p->next->prev = p->prev;
    else
        tail = p->prev;
}

class LFUCache {
public:
    LinkedNode* flist;
    LinkedNode* ftail;
    int curr;
    int max;
    unordered_map<int, LinkedNode*> mp;
    LFUCache(int capacity) {
        max = capacity;
        curr = 0;
        flist = new LinkedNode();
    }
    
    ~LFUCache() {
        delete flist;
    }
    
    VNode* visit(int key) {
        VNode* vn = (VNode*)mp[key];
        if(vn) {
            FNode* fn = (FNode*)vn->head;
            int f = fn->freq;
            
            FNode* fnext = (FNode*)fn->next;
            if(!fnext || fnext->freq != f + 1) {
                fnext = new FNode(f + 1);
                insertNext(fn, fnext, ftail);
            }
            // Move to the new freqency list. And remove old list if it's empty.
            removeNode(vn, fn->tail);
            if(fn->tail == fn->head) {
                removeNode(fn, ftail);
                delete fn;
            }
            vn->head = fnext;
            insertNext(fnext->head, vn, fnext->tail);
        }
        return vn;
    }
    
    int get(int key) {
        VNode* vn = visit(key);
        if(vn)
            return vn->val; 
        return -1;
    }
    
    void put(int key, int value) {
        if(!max) return;
        VNode* vn = visit(key);
        if(vn) {
            vn->val = value;
            return;
        }
        
        FNode* fn = (FNode*)flist->next;
        if(curr == max) {
            // Remove one element from current set.
            VNode* t = (VNode*)fn -> tail;
            removeNode(t, fn -> tail);
            mp.erase(t->key);
            delete t;
            if(fn->freq != 1 && fn->tail == fn->head) {
                removeNode(fn, ftail);
                delete fn;
                fn = NULL;
            }
        } else {
            ++curr;
        }
        
        if(!fn || fn->freq != 1) {
            fn = new FNode(1);
            insertNext(flist, fn, ftail);
        }
        vn = new VNode(key, value, fn);
        insertNext(fn->head, vn, fn->tail);
        mp[key] = vn;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
