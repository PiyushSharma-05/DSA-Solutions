class Solution {
public:
    set<vector<int>> s;
    void allPosSum(vector<int>& arr, int i, int tar, vector<vector<int>>& ans, vector<int>& combin){

        if( i >= arr.size() || tar < 0 ){
            return ;
        }

        if( tar == 0 ){
            if(s.find(combin) == s.end()){
            ans.push_back(combin);
            s.insert(combin);
            }
            return ;
        }

        combin.push_back(arr[i]);
        allPosSum(arr, i+1, tar-arr[i], ans, combin);
        allPosSum(arr, i, tar-arr[i], ans, combin);

        combin.pop_back();
        allPosSum(arr, i+1, tar, ans, combin);

    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin ;

        allPosSum(arr, 0, tar, ans, combin);

        return ans;
    }
};