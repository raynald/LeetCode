class Solution {
private:
    int factor[10];
    
public:
    string getPermutation(int n, int k) {
        int num[10];
        int a[10];
        
        string str="";factor[0]=1;
        factor[1]=1;a[0]=1;k--;
        for(int i=2;i<=n;i++) {
            factor[i]=factor[i-1]*i;
            a[i-1]=i;
        }
        for(int i=n-1;i>=0;i--) {
            if(k<factor[i]) {
                num[n-i-1] = a[0];
                for(int j=0;j<n;j++) a[j]=a[j+1];
            }
            else {
                num[n-i-1] = a[k/factor[i]];
                for(int j=k/factor[i];j<n;j++) a[j] = a[j+1];
                k = k%factor[i];
            }
        }
        for(int i=0;i<n;i++) str+=char('0'+num[i]);
        return str;
    }
};
