#include<iostream>
#include<vector>
using namespace std;
bool safe(vector<vector<int>>&board,int row,int col,int n){
    // check col;
    for(int i=0;i<n;i++){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n ;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board,int row,int n){
    if(row==n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(safe(board,row,i,n)){
            board[row][i]=1;
            if(solve(board,row+1,n)){
            return true;
        }
        board[row][i]=0;
        }
         
    }
    return false;

}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>board(n,vector<int>(n,0));
    if(solve(board,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"fuck u";
    }
}