class Solution {
public:
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *node, *tmp, *cur, *new_head;
        map<RandomListNode*, RandomListNode*> mmap;
        map<RandomListNode*, RandomListNode*>::iterator got;
        mmap.clear();
        
        node = head; new_head = cur = NULL;
        while(node!=NULL) {
            tmp = new RandomListNode(node->label);
            mmap.insert(pair<RandomListNode*,RandomListNode*>(node,tmp));
            if(cur==NULL) {
                new_head = tmp;
                cur = tmp;
            }
            else {
                cur -> next = tmp;
                cur = tmp;
            }
            node = node->next;
        }
        node = head; tmp = new_head;
        while(node!=NULL) {
           if(node->random!=NULL) {
               got = mmap.find(node->random);
               tmp->random = got->second;
           }
           node=node->next;
           tmp=tmp->next;
        }
        return new_head;
    }
};
