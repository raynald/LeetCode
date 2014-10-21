class LRUCache{
private:
    struct doubleList {
        doubleList *left, *right;
        int key;
        int val;
        doubleList() {}
        doubleList(int y, int x): key(y), val(x), left(NULL), right(NULL) {}
    };
    int cap;
    unordered_map<int, doubleList*> mmap;
    unordered_map<int, doubleList*>::const_iterator got;
    doubleList *head, *tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        mmap.clear();
        head = tail = NULL;
    }
    
    int get(int key) {
        doubleList *tmp;
        got = mmap.find(key);
        if(got==mmap.end()) return -1; else {
            tmp = got->second;
            if(tmp!=head) {
                tmp->left->right=tmp->right;
                if(tmp!=tail) tmp->right->left=tmp->left;
                else {
                    tail = tmp->left;
                }
                tmp->left = NULL;
                tmp->right = head;
                head->left = tmp;
                head = tmp;
            }
            return got->second->val;
        }
    }
    
    void set(int key, int value) {
        doubleList *tmp;
        got = mmap.find(key);
        if(got==mmap.end()) {
            if(mmap.size()==cap) {
                if(head!=tail) {
                    tmp = tail->left;
                    tmp->right = NULL;
                }
                else {
                    tmp = head = NULL;
                }
                mmap.erase(tail->key);
                delete tail;
                tail = tmp;
            }
            tmp = new doubleList(key, value);
            mmap.insert(pair<int, doubleList*>(key,tmp));
            if(head==NULL) {
                head = tail = tmp;
            }
            else {
                tmp->right=head;
                head->left = tmp;
                head = tmp;
            }
        }
        else {
            tmp = got->second;
            tmp -> val = value;
            if(tmp!=head) {
                tmp->left->right=tmp->right;
                if(tmp!=tail) tmp->right->left=tmp->left;
                else {
                    tail = tmp->left;
                }
                tmp->left = NULL;
                tmp->right = head;
                head->left = tmp;
                head = tmp;
            }
        }
    }
};
