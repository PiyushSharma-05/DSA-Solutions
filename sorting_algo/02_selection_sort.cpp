#include<iostream>
#include<vector>
using namespace std;

vector<int> selectionSort(vector<int> &nums,int n){

    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i; j<n; j++){
            if(nums[minIndex] > nums[j]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(nums[minIndex], nums[i]);
        }
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

    vector<int>sortedNums = selectionSort(nums, n);
    cout << "after sorting: ";
    for(int num: sortedNums){
        cout << num << " ";
    }

    return 0;
}


// Space: O(1)
// Time: Best O(N²) | Average O(N²) | Worst O(N²)