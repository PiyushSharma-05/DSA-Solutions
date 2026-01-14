#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int>arr, int c, int minAllowedDist){
    int cows=1, lastStall=arr[0];
    for(int i=0; i<arr.size(); i++){
        if(arr[i]-lastStall >= minAllowedDist){
            cows++;
            lastStall=arr[i];
        }
        if(cows==c) return true;
    }
    return false;
}

int largestMinDist(vector<int>&arr, int c){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int st=arr[0], end=arr[n-1]-arr[0], ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr, c, mid)){
            ans=mid;
            st=mid+1;
        } else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){

    vector<int>arr={1,2,8,4,9};
    int c = 3;

    cout << "Min number of max allowed min dist is: " << largestMinDist(arr,c) << endl ;
    return 0;
}
