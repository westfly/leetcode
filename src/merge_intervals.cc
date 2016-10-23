/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include "code_utils.h"
struct IntervalCmp {
	bool operator () (const Interval& a, const Interval& b)
	{
		return a.start < b.start;
	}
};
vector<Interval> merge(vector<Interval> &intervals) {
	if (intervals.size() <= 1) {
		return intervals;
	}
	std::sort(intervals.begin(), intervals.end(), IntervalCmp());
	vector<Interval> result(intervals.begin(), intervals.begin() + 1);
	int curr = 0;
	for(int i = 1;i < intervals.size(); ++i) {
		/*
		 [3, 14], [10, 13], [17, 18];
		 [3, 14]
		 [3, 14] [17, 18]
		 */

		if (result.back().end >= intervals[i].start) {
			int end = max(intervals[i].end,result.back().end);
            result.back().end = end;
		} else {
			result.push_back(intervals[i]);
		}
	}
};
int main(int argc, char **argv) {

	return 0;
}
