class Solution {
private:
    int n;
    vector<vector<int> > ans;
    vector<int> checklist;
public:
    void search(vector<int> c, int x, int y) {
        if(x>=n) {
            if(y==0) {
                ans.push_back(checklist);
            }
            else return;
        }
        else {
            search(c, x+1, y);
            for(int i=1;;i++) {
                if(c[x]*i>y) break;
                checklist.push_back(c[x]);
                search(c, x+1, y-c[x]*i);
            }
            while(!checklist.empty() && checklist.back()==c[x]) checklist.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        ans.clear();
        search(candidates, 0, target);
        return ans;
    }
};
