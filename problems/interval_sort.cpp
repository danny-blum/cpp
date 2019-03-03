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
    static bool intervalSort(Interval &a, Interval&b) {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> vout;
        
        if (intervals.size() == 0) return vout;
        std::sort(intervals.begin(), intervals.end(), intervalSort);
        
        Interval iprev = intervals[0];
        Interval *picur;
        
        for (int i=0; i<intervals.size(); ++i)
        {
            picur = &intervals[i];
            if (picur->start <= iprev.end)
            {
                iprev.end = max(picur->end, iprev.end);
            }
            else
            {
                vout.push_back(iprev);
                iprev = *picur;
            }
        }
        if (vout.size()==0 || iprev.end>vout[vout.size()-1].end)
            vout.push_back(iprev);
        
        return vout;
    }
};
