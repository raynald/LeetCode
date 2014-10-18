#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/**
 *  * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

bool comp(Interval &x, Interval &y) {
    return ((x.start < y.start) || (x.start== y.start && x.end<=y.end));
}

class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            if (intervals.size()==0) return intervals;
            sort(intervals.begin(), intervals.end(), comp);
            vector<Interval> results;
            results.clear();
            results.push_back(Interval(intervals[0].start, intervals[0].end));
            Interval top = intervals[0];
            for (int i=1;i < intervals.size();i ++) {
                if (intervals[i].start > top.end) {
                    top = intervals[i];
                    results.push_back(top);
                }
                else {
                    if(intervals[i].end > top.end) {
                        top.end = intervals[i].end;
                        results.pop_back();
                        results.push_back(top);
                    }
                }
            }
            return results;
        }
};

int main() {
    Solution sol;
    vector<Interval> test;
    vector<Interval> test2;
    for (int i=0;i<10;i++) {
        int x = rand()%30;
        test.push_back(Interval(x, x + rand()%20));
    }
    for (int i=0;i<test.size();i ++)
        cout << test[i].start << " " << test[i].end<<endl;
    puts("\n");
    test2 = sol.merge(test);
    for (int i=0;i<test2.size();i ++)
        cout << test2[i].start << " " << test2[i].end<<endl;
}
