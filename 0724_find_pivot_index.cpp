class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int preSum = 0, postSum = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
        }
        for(int j=0; j<nums.size(); j++){
            postSum = total - preSum - nums[j];
            if(preSum == postSum){
                return j;
            }
            preSum += nums[j];
        }
        return -1;
    }
};

Pattern: Prefix Sum
Space: O(1)
Time: O(N)