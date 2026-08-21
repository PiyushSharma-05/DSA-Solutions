#include<iostream>
#include<vector>
using namespace std;

vector<int> insertionSort(vector<int> &nums,int n){
    for(int i=1; i<n; i++){
        int key = nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
    return nums;
}

int main(){

    vector<int>nums = {6,7,1,9,2,8,0,5,3,4};
    int n = nums.size();
    cout << "before sorting: ";
    for(int num: nums){
        cout << num << " ";
    }
    cout << endl;

    vector<int>sortedNums = insertionSort(nums, n);
    cout << "after sorting: ";
    for(int num: sortedNums){
        cout << num << " ";
    }

    return 0;
}

// Space: O(1)
// Time: Best O(N) | Average O(N²) | Worst O(N²)