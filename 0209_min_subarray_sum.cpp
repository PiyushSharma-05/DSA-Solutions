#include<climits>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        bool exist = false;
        int left = 0, tarSum = 0;
        for(int right=0; right<nums.size(); right++){
            tarSum += nums[right];

            while(tarSum >= target){
                exist = true;
                minLen = min(minLen, right - left + 1) ;
                tarSum -= nums[left];
                left++;
            }
        }
        return exist? minLen:0;
    }
};

// Pattern: Sliding Window (Two Pointers)
// Space: O(1)
// Time: O(N)