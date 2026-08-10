class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long currSum = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            currSum += nums[right];

            if(right-left+1 > k){
                currSum -= nums[left];
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            if(right-left+1==k && freq.size()==k){
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};