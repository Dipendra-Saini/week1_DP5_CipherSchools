#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr){
    int p0 = 0,p1 =0,p2 = arr.size()-1;

    while(p1<=p2){
        switch (arr[p1]) {
            case 0:
                swap(arr[p0],arr[p1]);
                p0++;
                p1++;
                break;
            case 1:
                p1++;
                break;
            case 2:
                swap(arr[p2],arr[p1]);
                p2--;
                break;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<pair<int,int>> pair_of_zeroes;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j] == 0){
                pair_of_zeroes.push_back(make_pair(i,j));
            }
        }
    }

    for(auto i:pair_of_zeroes){
        for(int j=0;j<col;j++){
            matrix[i.first][j] = 0;
        }
        for(int j=0;j<row;j++){
            matrix[j][i.second] = 0;
        }
    }
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if(row<=0){
        return false;
    }
    int col = matrix[0].size()-1;
    row = 0;
    while(col>=0 && row<matrix.size()){
        if(target==matrix[row][col]){
            return true;
        }
        else if(target<matrix[row][col]){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}


int main(){

    vector<int> arr ={2,0,1,2,1,1,0,0,2,2,2,2};
//    vector<int> arr ={1,2,1,1,1,0,0,2};
    sort012(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;


//    vector<vector<int>> matrix= {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> matrix= {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    vector<vector<int>> matrixx= {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    cout<<"Element found : "<<searchMatrix(matrixx,15)<<endl;



    return 0;
}