#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> &nums){
    if(nums.size()<=2){
        return {};
    }
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;

    for(int i =0;i<nums.size();i++){
        int cur1 = nums[i];
        int start = i+1,end = nums.size()-1;

        while(start<=end){
            if(cur1+nums[start]+nums[end]==0){
                result.push_back({cur1,nums[start],nums[end]});
                start++;
                end--;
                while (start<end && nums[start-1] == nums[start]){
                    start++;
                }
                while (start<end && nums[end] == nums[end+1]) {
                    end--;
                }
            } else if(cur1+nums[start]+nums[end]<0){
                start++;
            }
            else{
                end--;
            }
        }
        while(i<nums.size()-1&& nums[i]==nums[i+1] ){
            i++;
        }
        return result;

    }
}

int peakIndexInMountainArray(vector<int>& arr) {
    int start =1,end=arr.size()-2;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid-1] < arr[mid]  && arr[mid] > arr[mid+1])
            return mid;

        if(arr[mid-1] > arr[mid])
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

int search_sorted_array(vector<int>& nums,int start,int end, int target){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;

    if(nums[mid]==target){
        return mid;
    }

    if(nums[start]<=nums[mid]){
        //left section is sorted haah
        if(target>=nums[start] && target<=nums[mid]){
            return search_sorted_array(nums,start,mid-1,target);
        }
        else{
            return search_sorted_array(nums,mid+1,end,target);
        }
    }
    else{
        if(target>=nums[mid] && target<=nums[end]){
            return search_sorted_array(nums,mid+1,end,target);
        }
        else{
            return search_sorted_array(nums,start,mid-1,target);
        }
    }
}

int search(vector<int>& nums, int target) {
    int result = search_sorted_array(nums,0,nums.size()-1,target);
    return result;

}

int main(){
    vector<int> nums1 = {7,8,9,2,3,4,5,6};
    vector<int> nums2 = {4,5,6,7,-1,-2,-2,-3,-3,-4,0,1,2};
    int index = search(nums2,0);
    cout<<index<<endl;
    cout<<peakIndexInMountainArray(nums1)<<endl;
    vector<vector<int>> result;
    result = triplets(nums2);
    for(auto row : result){
        for (auto i : row){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}