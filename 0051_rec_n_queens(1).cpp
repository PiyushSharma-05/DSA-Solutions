#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string>& board, int n, int row, int col){
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    for(int i=0; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void nQueens(vector<string>& board, vector<vector<string>>& ans, int n, int row){
    if( row == n ){
        ans.push_back(board);
        return ;
    }

    for(int j=0; j<n; j++){
        if(isSafe(board, n, row, j)){
            board[row][j] = 'Q';
            nQueens(board, ans, n, row+1);

            board[row][j] = '.';
        }
    }
}

vector<vector<string>> getQueens(int n){
    vector<string> board(n, string(n, '.'));

    vector<vector<string>> ans;

    nQueens(board, ans, n, 0);

    return ans;
}

int main(){

    int n = 4;

    vector<vector<string>> result = getQueens(n);

    for( const auto& getQueens : result){
        cout << "{ ";
        for(string val : getQueens ){
            cout << val << "  ";
        }
        cout << "} ";
    }
    cout << endl;

    return 0;
}