/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval const &x, Interval const &y) {
    return x.start<y.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end(), comp);
            vector<Interval> results;
            results.clear();
            Interval top = intervals[0];
            results.push_back(top);
            for (int i=1;i < intervals.size();i ++) {
                if (intervals[i].start > top.end) {
                    top = intervals[i];
                    results.push_back(top);
                }
                else {
                    if(intervals[i].end > top.end) {
                        top.end=intervals[i].end;
                        results.back().end=intervals[i].end;
                    }
                }
            }
            return results;
    }
};


