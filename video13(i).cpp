#include <bits/stdc++.h>
using namespace std;

bool word_search(vector<vector<char>> &board, string word, int i, int j ,int k){
    int n = board.size();
    int m = board[0].size();
    if(k==word.size()) return true;
    if(i<0||i>=n||j<0||j>=m||word[k]!=board[i][j]||board[i][j]=='#') return false;
    char ch = board[i][j];
    board[i][j]='#';
    bool op1 = word_search(board,word,i-1,j,k+1);
    bool op2 = word_search(board,word,i,j+1,k+1);
    bool op3 = word_search(board,word,i+1,j,k+1);
    bool op4 = word_search(board,word,i,j-1,k+1);
    board[i][j]=ch;
    return op1||op2||op3||op4;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(word_search(board,word,i,j,0)) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
//    string word = "ABCCEDE";
    cout<<bool(exist(board,word))<<endl;
    return 0;
}