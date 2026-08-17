class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> map;
        map[0] = -1;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            int remainder = sum%k;

            if(remainder < 0){
                remainder += k;
            }
            if(map.count(remainder)){
                if(i-map[remainder] >= 2){
                    return true;
                }
            } else{
                map[remainder] = i;
            }
        }
        return false;
    }
};


// Pattern: Prefix Sum with Hash Map (Remainder Tracking / Modulo Arithmetic)
// Space: O(min(N, K))
// Time: O(N)