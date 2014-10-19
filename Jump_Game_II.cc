struct cmp {
    int index;
    int val;
    cmp() {}
    cmp(int x, int y): index(x), val(y) {}
};

bool operator<(const cmp &x, const cmp &y) {
    return x.val>y.val;
}

class Solution {
    private:
    public:
        int jump(int A[], int n) {
            priority_queue<cmp> q;
            cmp now;
            bool v[n];

            memset(v,0,sizeof(v));
            while(!q.empty()) q.pop();
            q.push(cmp(0,0));
            v[0]=1;
            if(n==1) return 0;
            while(!q.empty()) {
                now = q.top();
                q.pop();
                for(int i=A[now.index];i>=1;i--) {
                    if(now.index+i==n-1) return now.val+1;
                    if(!v[now.index+i]) {
                        v[now.index+i]=1;
                        q.push(cmp(now.index+i,now.val+1));
                    }
                }
            }
        }
};
