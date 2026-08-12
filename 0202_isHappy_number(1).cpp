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
        int slow = n;
        int fast = getNext(n);

        while(slow!=1 && slow!=fast){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return slow == 1;
    }
};

// Pattern: Hash Set for Cycle Detection
// Space: O(log N)
// Time: O(log N)