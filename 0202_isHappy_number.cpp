class Solution {
private: 
    int getNext(int n){
        int totalSum = 0;
        while(n>0){
            int d = n % 10;
            totalSum += d*d;
            n /= 10;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n!=1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};

// Pattern: Fast & Slow Pointers (Floyd's Cycle Detection)
// Space: O(1)
// Time: O(log N)