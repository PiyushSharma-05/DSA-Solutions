class Solution{
public:
    bool canAttendMeetings(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());

        int i = 0, n = intervals.size();
        while(i<n-1){
            if(intervals[i][1] > intervals[i+1][0]){
                return false;
            }
            i++;
        }
        return true;
    }
};


// Pattern: Intervals (Sorting + Overlap Check)
// Space: O(1) — or O(log N) depending on sort space complexity
// Time: O(N log N)