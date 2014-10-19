class Solution {
    public:
        int diff(int x, int y) {
            return x>y?x-y:y-x;
        }
        int find_less(vector<int> &num, int left, int right, int x) {
            int tmp;

            if(left>right) return 2000000000;
            int mid=(left+right)/2;
            if(num[mid]==x) return x;
            if(num[mid]<x) {
                tmp = find_less(num, mid+1, right, x);
                if(diff(tmp,x)<x-num[mid]) return tmp; else return num[mid];
            }
            if(num[mid]>x) {
                return find_less(num, left, mid-1, x);
            }
        }
        int find_more(vector<int> &num, int left, int right, int x) {
            int tmp;
            if(left>right) return 2000000000;
            int mid=(left+right)/2;
            if(num[mid]==x) return x;
            if(num[mid]<x) {
                return find_more(num, mid+1, right, x);
            }
            if(num[mid]>x) {
                tmp = find_more(num, left, mid-1, x);
                if(diff(tmp,x)<num[mid]-x) return tmp; else return num[mid];
            }
        }
        int threeSumClosest(vector<int> &num, int target) {
            int n = num.size();
            int sum;
            int summary;
            int ans;

            ans = 2000000000;
            sort(num.begin(), num.end());
            for(int i=0;i<n; i ++) {
                if(i>0 && num[i]==num[i-1]) continue;
                for(int j=i+1;j<n;j++) {
                    if(j>i+1 && num[j]==num[j-1]) continue;
                    sum=find_less(num, j+1, n-1, target-num[i]-num[j]);
                    summary = sum + num[i]+num[j];
                    if(diff(summary,target)<diff(ans,target)) ans = summary;
                    sum=find_more(num, j+1, n-1, target-num[i]-num[j]);
                    summary = sum + num[i]+num[j];
                    if(diff(summary,target)<diff(ans,target)) ans = summary;
                }
            }
            return ans;
        }
};

