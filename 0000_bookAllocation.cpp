#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>arr,int m, int maxAllowedPages){
    int students=1;
    int pages=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>maxAllowedPages) return false;
        if(arr[i]+pages<=maxAllowedPages){
            pages+=arr[i];
        } else{
            students++;
            pages=arr[i];
        }
    }
    return students > m ? false : true ;
}

int allocate(vector<int>&arr, int m){
    int n=arr.size();
    int sum=0, ans=-1;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int st=0, end=sum;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr,m,mid)){
            ans=mid;
            end=mid-1;
        } else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int>arr={2,1,3,4};
    int m = 2;

    cout << "Min number of max allowed pages are: " << allocate(arr,m) << endl ;
    return 0;
}
