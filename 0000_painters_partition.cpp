#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>arr, int m, int maxAllowedTime){
    int painters=1;
    int time=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>maxAllowedTime) return false;
        if(arr[i]+time<=maxAllowedTime){
            time+=arr[i];
        } else{
            painters++;
            time=arr[i];
        }
    }
    return painters>m ? false : true;
}

int allocateTime(vector<int>&arr, int m){
    int n=arr.size();
    int sum=0, ans=-1,maxValue=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxValue=max(maxValue,arr[i]);
    }
    int st=maxValue, end=sum;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr, m, mid)){
            ans=mid;
            end=mid-1;
        } else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int>arr={40,30,10,20};
    int m = 2;

    cout << "Min number of max allowed time is: " << allocateTime(arr,m) << endl ;
    return 0;
}
