class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1;
        int left = 0, currSum = 0;
        for(int right=0; right<nums.size(); right++){
            currSum += nums[right];

            while(currSum >= target){
                minLen = min(minLen, right - left + 1) ;
                currSum -= nums[left++];
            }
        }
        return minLen == n+1 ? 0 : minLen;
    }
};

// Pattern: Sliding Window (Two Pointers)
// Space: O(1)
// Time: O(N)