/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> vret;
        int startPos;
        int endPos;
        bool endOverlap;
        
        // find start location
        int i;
        for (i=0; i<=intervals.size(); ++i)
        {
            if (i == intervals.size())
            {
                startPos = i;
                break;
            }
            if (newInterval.start<intervals[i].start || newInterval.start<=intervals[i].end)
            {
                startPos = i;
                break;
            }
        }
        
        // find end location
        for (i=i; i<=intervals.size(); ++i)
        {
            if (i == intervals.size())
            {
                endPos = i;
                endOverlap = false;
                break;
            }
            if (newInterval.end < intervals[i].start)
            {
                endPos = i;
                endOverlap = false;
                break;
            }
            if (newInterval.end <= intervals[i].end)
            {
                endPos = i;
                endOverlap = true;
                break;
            }
        }
        
        int newStart;
        int newEnd;
        for (i=0; i<intervals.size(); ++i)
        {
            if (i<startPos || i>endPos)
            {
                vret.push_back(intervals[i]);
            }
            if (i == startPos)
            {
                newStart = min(newInterval.start, intervals[i].start);
            }
            if (i == endPos)
            {
                if (!endOverlap)
                {
                    newEnd  = newInterval.end;
                    vret.push_back(Interval(newStart, newEnd));
                    vret.push_back(intervals[i]);
                }
                else
                {
                    newEnd = intervals[i].end;
                    vret.push_back(Interval(newStart, newEnd));
                }
            }
        }
        
        if (endPos == intervals.size())
        {
            if (startPos == intervals.size())
                newStart = newInterval.start;
            vret.push_back(Interval(newStart, newInterval.end));
        }
        
        return vret;
    }
};
