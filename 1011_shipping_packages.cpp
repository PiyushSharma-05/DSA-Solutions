class Solution {
public:
    bool isValid(vector<int> & weights, int days, int minWeight){
        int curWeight = 0, numDays = 1;
        for(int w : weights){
            if(curWeight + w > minWeight){
                curWeight = w;
                numDays++;
            } else{
                curWeight += w;
            }
        }
        return numDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // int st = *max_element(weights.begin(), weights.end());
        // int end = accumulate(weights.begin(), weights.end(), 0);
        int st = 0, end = 0;
        for(int w : weights){
            st = max(st, w);
            end += w;
        }
        int ans = end;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(isValid(weights, days, mid)){
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};


// Pattern: Binary Search on Answer Space
// Space: O(1)
// Time: O(N log(Sum - Max))