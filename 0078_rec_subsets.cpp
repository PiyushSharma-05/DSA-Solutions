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
    getSubsets(nums, i+1, ans, allSubsets);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;

        vector<vector<int>> allSubsets;

        getSubsets(nums, 0, ans, allSubsets);

        return allSubsets;
    }
};