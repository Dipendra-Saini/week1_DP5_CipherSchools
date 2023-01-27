#include <bits/stdc++.h>
using namespace std;
bool isValid(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty() == true)
            {
                return false;
            }
            char top = s.top();
            if ((top == '{' && ch == '}') || (top == '(' && ch == ')') || (top == '[' && ch == ']'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int minSwaps(string s) {
    int open = 0, ans = 0;
    for(char c : s) {
        if(c == ']') {
            if(open)  open--;
            else ans++,open++;
        } else open++;
    }
    return ans;
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;



    sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];



    for(auto it : intervals)
    {
        if(temp[1] >= it[0])
        {
            temp[1] = max(temp[1],it[1]);

        }
        else
        {
            ans.push_back(temp);
            temp = it;
        }
    }

    ans.push_back(temp);

    return ans;
}
int main(){
    return 0;
}