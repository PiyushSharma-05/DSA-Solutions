class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxNum=0;
        unordered_map<char, int> freq;
        int left=0;
        for(int right=0; right<s.size(); right++){
            freq[s[right]]++;

            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            maxNum = max(maxNum, right-left+1);
        }
        return maxNum;
    }
};