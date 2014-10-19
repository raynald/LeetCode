class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n;
        int pos;
        int ans;
        int tmp;
        
        n= num.size();
        if(n==1) return;
        pos = -1;
        for(int i=n-2;i>=0;i--) {
            if(num[i]<num[i+1]) {
                pos = i;
                break;
            }
        }
        if(pos==-1) {
            for(int i=0;i<n/2;i++) {
                tmp=num[i];
                num[i]=num[n-1-i];
                num[n-1-i]=tmp;
            }
        }
        else {
            ans = -1;
            for(int i=pos+1;i<n;i++) {
                if(ans == -1 || num[i]>num[pos] && num[i]<num[ans]) {
                    ans = i;
                }
            }
            tmp=num[pos];num[pos]=num[ans];num[ans]=tmp;
            sort(num.begin()+pos+1, num.end());
        }
    }
};
