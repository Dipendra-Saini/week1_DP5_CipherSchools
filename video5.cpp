#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    vector<vector<int>>::iterator it;
    for(auto &it : matrix)
    {
        reverse(it.begin(),it.end());
    }
}

void print(vector<vector<int>> matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    print(matrix);
    rotate(matrix);
    cout<<endl;
    print(matrix);
    return 0;
}