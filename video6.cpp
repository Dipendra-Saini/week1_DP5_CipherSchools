#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>matrix) {
    int top = 0;
    int bottom = matrix.size()-1;
    int left = 0;
    int right = matrix[0].size()-1;
    int index =0;
    vector<int> res((bottom+1)*(right+1));

    while (top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res[index] = matrix[top][i];
            index++;
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res[index] = matrix[i][right];
            index++;
        }
        right--;
        if(top<=bottom){
            for(int i= right;i>=left;i--){
                res[index] = matrix[bottom][i];
                index++;
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                res[index] = matrix[i][left];
                index++;
            }
            left++;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> result;
    result = spiralOrder(matrix);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}