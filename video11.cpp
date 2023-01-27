#include<bits/stdc++.h>
using namespace std;

void generate(string &genstr,int open,int close,vector<string> &result){
    if(open>close){
        return;
    }
    if(open <0 || close < 0){
        return;
    }
    if(open ==0 && close == 0){
        result.push_back(genstr);
        return;
    }

    genstr.push_back('(');
    generate(genstr,open-1,close,result);
    genstr.pop_back();

    genstr.push_back(')');
    generate(genstr,open,close-1,result);
    genstr.pop_back();


}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    int open = n;
    int close = n;
    string genstr = "";

    generate(genstr,open,close,result);
    return result;

}


void allarrangement(vector<int> &nums,int start,int end, vector<vector<int>> &result){
    if(start>end){
        result.push_back(nums);
        return;
    }
    for(int j=start;j<nums.size();j++){
        swap(nums[start],nums[j]);
        allarrangement(nums,start+1,end,result);
        swap(nums[start],nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    int start = 0;
    int end = nums.size()-1;

    allarrangement(nums,start,end,result);
    return result;
}


void findallcombination(string &digits,int start,int end , unordered_map<char,string> &um,string &genstr,vector<string> &result){
    if(start>end){
        result.push_back(genstr);
        return;
    }

    auto get_str = um.at(digits[start]);

    for(auto i : get_str){
        genstr.push_back(i);
        findallcombination(digits,start+1,end,um,genstr,result);
        genstr.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    if(digits.size() == 0){
        return {};
    }
    unordered_map<char,string> um = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
    };
    int start = 0;
    int end = digits.size()-1;
    string genstr ="";
    vector<string> result;
    findallcombination(digits,start,end,um,genstr,result);
    return result;
}


void generatesubset(vector<int>&nums,int start,int end,vector<int>subset,vector<vector<int>> &result) {
    if (start==end) {
        result.push_back(subset);
        return;
    }
    subset.push_back(nums[start]);
    generatesubset(nums,start+1,end,subset,result);

    subset.pop_back();
    generatesubset(nums,start+1,end,subset,result);
}


vector<vector<int>> subsets(vector<int>& nums) {
    int start =0;
    int end = nums.size();

    vector<vector<int>> result;
    vector<int> subset;

    generatesubset(nums,start,end,subset,result);
    return result;

}


int main(){

//    string digits = "2345";
//    vector<string> vc;
//    vc = letterCombinations(digits);
//    for(auto i : vc){
//        cout<<i<<" ";
//    }
//    cout<<endl;


//    vector<int> nums = {1,2,3};
//    vector<vector<int>> result;
//    result = permute(nums);
//    for(auto row:result){
//        for(auto col:row){
//            cout<<col<<" ";
//        }
//        cout<<endl;
//    }

//    vector<string> result;
//    int n=3;
//    result = generateParenthesis(n);
//    for(auto i : result){
//        cout<<i<<" ";
//    }
//    cout<<endl;



    vector<int> nums = {1,2,3};
    vector<vector<int>> result;
    result = subsets(nums);
    for(auto row:result){
        for(auto col:row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}