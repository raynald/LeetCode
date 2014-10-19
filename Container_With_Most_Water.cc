class Solution {
    private:
        int ans;
        vector<int> h;

    public:
        int min(int x, int y) {
            return x>y?y:x;
        }

        void search(int left, int right) {
            if(left>=right) return;
            if(h[left]<h[right]) {
                if(h[left]*(right-left)>ans) ans = h[left]*(right-left);
                search(left+1, right);
            }
            else {
                if(h[right]*(right-left)>ans) ans = h[right]*(right-left);
                search(left, right-1);
            }
        }

        int maxArea(vector<int> &height) {
            int n;
            h = height;
            n=height.size();

            ans = 0;
            search(0, n-1);
            return ans;
        }
};

