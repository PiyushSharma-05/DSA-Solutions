class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, idx = 0;

        while( i < n ){
            nums[idx++] = nums[i++];
            while(i<n && (nums[i-1] == nums[i])) i++;

        }
        return idx;
    }
};