/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mmap;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::const_iterator got;
    
public:
    UndirectedGraphNode *clone(UndirectedGraphNode *head) { 
        vector<UndirectedGraphNode *> nbr;
        UndirectedGraphNode *temp, *new_head;
        if(head==NULL) return NULL;
        got = mmap.find(head);
        if(got==mmap.end()) {
            new_head = new UndirectedGraphNode(head->label);
            mmap.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(head, new_head));
            nbr.clear();
            for(int i=0;i<head->neighbors.size();i++) {
                nbr.push_back(clone(head->neighbors[i]));
            }       
            new_head->neighbors=nbr;
        }
        else return got->second;
        return new_head;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *temp, *head, *new_head;
        
        mmap.clear();
        new_head = clone(node);
        return new_head;
    }
};
