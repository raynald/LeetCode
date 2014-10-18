#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() {start=0; end=0;}
    Interval(int x, int y) {start=x; end = y;}
};

bool comp(Interval const &x, Interval const &y) {
    return x.start<y.start;
}

class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            if (intervals.size()==0) return intervals;
            sort(intervals.begin(), intervals.end(), comp);
            vector<Interval> results;
            results.clear();
            Interval top = Interval(intervals[0].start, intervals[0].end);
            results.push_back(top);
            for (int i=1;i < intervals.size();i ++) {
                if (intervals[i].start > top.end) {
                    top = Interval(intervals[i].start, intervals[i].end);
                    results.push_back(top);
                }
                else {
                    if(intervals[i].end > top.end) {
                        top.end = intervals[i].end;
                        results.back().end=intervals[i].end;
                    }
                }
                cout << results.back().start << " " << results.back().end<<endl;
            }
            return results;
        }
};
