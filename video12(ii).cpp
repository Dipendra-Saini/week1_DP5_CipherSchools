#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> &chess,int x, int y, const int &N){
    for(int i=x;i>=0;i--){
        if(chess[i][y]){
            return false;
        }
    }
    for(int i=x,j=y;i>=0 && j>=0;i--,j--){
        if(chess[i][y]){
            return false;
        }
    }
    for(int i=x,j=y;i<N && j>=0;i++,j--){
        if(chess[i][y]){
            return false;
        }
    }
    return true;

}

bool NQueen(vector<vector<bool>> &chess,int y, const int &N){
    if(y==N){
        return true;
    }

    for(int x=0;x<N;x++){
        if(isSafe(chess,x,y,N)){
            chess[x][y] = true;
            if(NQueen(chess,y+1,N)){
                return true;
            }
            chess[x][y] = false;
        }
    }
    return false;
}

vector<vector<bool>> NQueen(int N){
    vector<vector<bool>> chess(N,vector<bool>(N,false));
    NQueen(chess,0,N);
    return chess;
}

int main(){
    int n;
    cin>>n;
    vector<vector<bool>> result;
    result = NQueen(n);
    for(auto row:result){
        for(auto col : row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}