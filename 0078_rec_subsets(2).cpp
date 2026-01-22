#include<iostream>
#include<vector>
// #include<unordered_map>
using namespace std;

void getSubset(vector<int>& arr, vector<vector<int>>& allSubsets,vector<int>& ans, int i){

    if( i == arr.size()){
        allSubsets.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    getSubset(arr,allSubsets,ans,i+1);

    ans.pop_back();
    getSubset(arr,allSubsets,ans,i+1);

}

vector<vector<int>> subsets(vector<int>& arr){
    vector<int> ans;
    vector<vector<int>> allSubsets;

    getSubset(arr, allSubsets,ans, 0);

    return allSubsets;
}

int main(){
    vector<int> arr = {1,2,3};

    vector<vector<int>> Subsets = subsets(arr);

    for(const auto& subsets : Subsets){
        cout << "{ ";
        for(int num : subsets){
            cout << num << " ";
        }
        cout << "}";
    }
    cout << endl;

    return 0;
}