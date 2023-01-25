#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    vector<int> lmax(height.size());
    vector<int> rmax(height.size());
    lmax[0] = height[0];
    for(int i=1;i<lmax.size();i++){
        if(height[i]>lmax[i-1]){
            lmax[i] = height[i];
        }
        else{
            lmax[i] = lmax[i-1];
        }
    }
    rmax[height.size()-1] = height[height.size()-1];
    for(int i= height.size()-2;i>=0;i--){
        if(height[i]>rmax[i+1]){
            rmax[i] = height[i];
        } else{
            rmax[i] = rmax[i+1];
        }
    }
    int res=0;
    for(int i=0;i<height.size();i++){
        res=res+(min(lmax[i],rmax[i])-height[i]);
    }
    return res;
}

int main(){

    vector<int> height = {4,2,0,3,2,5};
    int result;
    result = trap(height);
    cout<<result<<endl;
    return 0;
}