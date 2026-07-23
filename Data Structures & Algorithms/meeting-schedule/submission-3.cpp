/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            ans.push_back({intervals[i].start,intervals[i].end});
        }
        sort(ans.begin(),ans.end());
        int last=ans[0][1];
        for(int i=1;i<ans.size();i++){
            if(last>ans[i][0]){
                return false;
            }
            else{
                last=ans[i][1];
            }
        }
        return true;
    }
};
