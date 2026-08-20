#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int> &nums, int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return nums;
}

int main(){

    vector<int>nums = {9,8,7,6,5,4,3,2,1};
    int n = nums.size();
    cout << "before sorting: ";
    for(int num: nums){
        cout << num << " ";
    }
    cout << endl;

    vector<int>sortedNums = bubbleSort(nums, n);
    cout << "after sorting: ";
    for(int num: sortedNums){
        cout << num << " ";
    }

    return 0;
}


// Space: O(1)
// Time: O(N²) worst/average, O(N) best case