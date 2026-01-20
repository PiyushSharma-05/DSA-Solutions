class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int idx = 0, i = 0;
        
        while(i < n){
           if(nums[i] != val){
            nums[idx++] = nums[i++];
           } else{
            i++;
           }
        }
        return idx;
    }
};