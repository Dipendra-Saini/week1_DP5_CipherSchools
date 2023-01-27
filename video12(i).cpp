#include<bits/stdc++.h>
using namespace std;

multimap<int,int > mp = {{1,0},{0,1},{-1,0},{0,-1}};
int isvalid(int row,int col,vector<vector<int>> &v,vector<vector<int>> &b,int n){
    return ((row>=0 && row<n) && (col>=0 && col<n) && (v[row][col]==0 && b[row][col]==0));
}
int solve(int row,int col,int finalx,int finaly, vector<vector<int>> &v,int n,vector<vector<int>> &b){

    if (row==finalx && col == finaly){
        return 1;
    }
    if (row>=n || row<0 || col>=n || col<0)
        return 0;
    int count =0;
    b[row][col]=1;
    for(auto i: mp){
        int first = i.first;
        int second = i.second;
        row+=first;
        col+=second;
        if (isvalid(row,col,v,b,n)){

            count+=solve(row,col,finalx,finaly,v,n,b);

        }
        row-=first;
        col-=second;
    }
    b[row][col]=0;
    return count;

}
int main() {
    int n,ele,m,c;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0)),b(n,vector<int>(n,0));
    for(int i=0 ;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    b[0][0]=1;
    cout<<solve(0,0,n-1,n-1,v,n,b);
    return 0;
}