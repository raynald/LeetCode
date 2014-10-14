/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct coco {
    double l;
    double r;
    coco() : l(0), r(0) {}
};

double diff(const coco &x, const coco &y) {
    return sqrt((x.l-y.l)*(x.l-y.l)+(x.r-y.r)*(x.r-y.r));
}

bool comp(const coco &x, const coco &y) {
    return (x.l<y.l) || (fabs(x.l-y.l)<0.000001 && x.r<y.r);
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int x1,y1,x2,y2;
        int n = points.size();
        if (n<2) return n;
        coco p[n+1];
        coco tmp;
        int max, ans, k, same;
        
        ans = 2;
        for(int i=0;i<n;i++) {
            x1=points[i].x;
            y1=points[i].y;
            same = 1;
            k = i;
            max = 0;
            for(int j=i+1;j<n;j++) {
                x2=points[j].x;
                y2=points[j].y;
                if(x1==x2) {
                    if(y1==y2) same++;
                    else {
                        k++;
                        p[k].l=-1;
                        p[k].r=x1;
                    }
                }
                else {
                    k++;
                    if(y1==y2) {
                        p[k].l=0;
                        p[k].r=y1;
                    }
                    else {
                        p[k].l=(y2-y1)*1.0/(x2-x1);
                        p[k].r=(-x1*y2+y1*x2)*1.0/(x2-x1);
                    }
                }
            }
            sort(p+i+1,p+k+1,comp);
            if(k>i) {
                tmp = p[i+1];
                max = 1;
                for(int j=i+2;j<=k;j++) {
                    if(diff(tmp,p[j])<0.000001) {
                        max ++;
                        if(max+same>ans) ans=max+same;
                    }
                    else {
                        tmp = p[j];
                        max=1;
                    }
                }
            }
            if(max+same>ans) ans=max+same;
        }
        return ans;
    }
};
