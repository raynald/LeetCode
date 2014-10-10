#include<cstdio>

using namespace std;

int a[110];
int n;
int key;

int search(int left, int right, int x) {
    if(left>right) return -1;
    if(left==right) {
        if(a[left]==x) return left; else return -1;
    }

    if(a[left]>a[right]) {
        int m=(left+right)/2;
        if (a[m]==x) return m;
        else {
            int t = search(left, m-1, x);
            if(t==-1) return search(m+1, right, x); else return t;
        }
    }
    else {
        int m = (left + right)/2;
        if (a[m]==x) return m;
        if (a[m]<x) {
            return search(m+1, right, x);
        }
        else {
            return search(left, m-1 , x);
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    puts("input the value:");
    scanf("%d",&key);
    int x = search(1, n, key);
    printf("%d\n",x);
    return 0;
}
