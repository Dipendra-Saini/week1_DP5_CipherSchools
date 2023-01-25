#include <bits/stdc++.h>
using namespace std;

vector<int> search_Range1(vector<int>& nums, int target) {
    int res1 = -1;
    int res2 = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            res1 = i;
            break;
        }
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            res2 = i;
        }
    }
    return {res1,res2};
}

int firstoccurence(vector<int>& nums,int start,int end, int target){
    if(start>end){
        return -1;
    }
    else if(start==end){
        if(nums[start]==target){
            return start;
        }
        else{
            return -1;
        }
    }
    else{
        int mid = start+ (end-start)/2;
        if(nums[mid]<target){
            return firstoccurence(nums,mid+1,end,target);
        }
        else if(nums[mid]>target){
            return firstoccurence(nums,start,mid-1,target);
        }
        else{
            if(mid==0 || (mid>0 && nums[mid-1]<target)){
                return mid;
            }
            else{
                return firstoccurence(nums,start,mid-1,target);
            }
        }
    }
}
int lastoccurence(vector<int>& nums,int start,int end, int target){
    if(start>end){
        return -1;
    }
    else if(start==end){
        if(nums[start]==target){
            return start;
        }
        else{
            return -1;
        }
    }
    else{
        int mid = start+ (end-start)/2;
        if(nums[mid]<target){
            return lastoccurence(nums,mid+1,end,target);
        }
        else if(nums[mid]>target){
            return lastoccurence(nums,start,mid-1,target);
        }
        else{
            if(mid==end || (mid<end && nums[mid+1]>target)){
                return mid;
            }
            else{
                return lastoccurence(nums,mid+1,end,target);
            }
        }
    }
}

vector<int> search_Range2(vector<int>& nums, int target) {
       int findex = firstoccurence(nums,0,nums.size()-1,target);
       int lindex = lastoccurence(nums,0,nums.size()-1,target);
       return {findex,lindex};
}

int main(){
    vector<int> nums = {1,2,3,3,4,5,5,8,9};
    vector<int> result1;
    vector<int> result2;
    result1 = search_Range1(nums,5);          //brute force accepted solution with T.C =>O(n)
    for(auto i:result1){
        cout<<i<<" ";
    }
    cout<<endl;
    result2 = search_Range2(nums,5);          //optimize solution with binary search T.C =>O(log(n))
    for(auto i:result2){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}