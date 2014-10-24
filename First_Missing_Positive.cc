class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_map<int, bool> mmap;
        unordered_map<int, bool>::const_iterator got;
        mmap.clear();
        for(int i=0;i<n;i++) {
            if(A[i]>0) mmap.insert(pair<int, bool>(A[i],1));
        }
        for(int i=1;;i++) {
            got = mmap.find(i);
            if(got==mmap.end()) return i;
        }
    }
};
