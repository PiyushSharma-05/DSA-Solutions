class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(const auto& interval : intervals){
            if(ans.empty() || ans.back()[1] < interval[0]){
                ans.push_back(interval);
            } else{
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};

// Pattern: Merge Intervals (Sorting + Greedy)
// Space: O(N) — or O(log N) depending on sort space complexity excluding output
// Time: O(N log N)