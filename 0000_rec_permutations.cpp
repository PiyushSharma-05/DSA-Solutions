#include<iostream>
#include<vector>
using namespace std;

void getPerm(vector<int>& arr, vector<vector<int>>& allPerm, int idx){
    if( idx == arr.size() ){
        allPerm.push_back(arr);
        return ;
    }

    for(int i=idx; i<arr.size(); i++){
        swap(arr[idx],arr[i]);
        getPerm(arr, allPerm, idx+1);

        swap(arr[idx],arr[i]);

    }
}

vector<vector<int>> perm(vector<int> arr){

    vector<vector<int>> allPerm;

    getPerm(arr, allPerm, 0);

    return allPerm;
}

int main(){

    vector<int> arr = {1,2,3};
    vector<vector<int>> result = perm(arr);

    for(const auto& permutations : result){
        for(int val : permutations){
            cout << val << " ";
        }
        cout << " , ";
    }
    cout << endl ;

    return 0;
}