class Solution {
public:

    void getSubsets(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& allSubsets){
        if( i == nums.size()){
            allSubsets.push_back({ans});
            return ;
        }

        ans.push_back(nums[i]);
        getSubsets(nums, i+1, ans, allSubsets);

        ans.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        
        getSubsets(nums, idx, ans, allSubsets);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        vector<vector<int>> allSubsets;

        getSubsets(nums, 0, ans, allSubsets);

        return allSubsets;
    }
};