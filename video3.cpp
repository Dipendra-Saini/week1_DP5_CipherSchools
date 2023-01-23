#include<bits/stdc++.h>
using namespace std;

//Easy Q1:- Merge sorted Arrays

void merge_sorted_arrays(vector<int> &arr1,int n,vector<int> &arr2,int m){
    int i=n-1;
    int j=m-1;
    int k=m+n-1;
    while (i>=0 && j>=0){
        if(arr1[i]>arr2[j]){
            arr1[k]=arr1[i];
            i--;
        }
        else{
            arr1[k]=arr2[j];
            j--;
        }
        k--;
    }
    while(j>=0){
        arr1[k]=arr2[j];
        j--;k--;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n+m);
    vector<int> arr2(m);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    merge_sorted_arrays(arr1,n,arr2,m);

    for(auto i : arr1){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}