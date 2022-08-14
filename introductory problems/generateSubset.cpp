#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> generateSubset(vector<int>ques){
//     if(ques.size()==0) return {{}};
//     vector<vector<int>> res;

//     for(auto i:ques){

//     }
// }

void solve(vector<int> nums, vector<int> &output, int index, vector<vector<int>>& ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index+1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
        
    }

    vector<vector<int>> answ;
    void generate(vector<int>& nums,vector<int>& subset,int i){
        if(i == nums.size()){
            answ.push_back(subset);
            return;
        }
        
        //When we are not considering ith value in subset
        generate(nums,subset,i+1);
        
      //When we are considering ith value in subset
        subset.push_back(nums[i]);
        generate(nums,subset,i+1);
        subset.pop_back();
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>nums{1,2,3};
    vector<int>subset;
    cout<<"Backtrack call...\n";
    generate(nums,subset,0);
    for(auto i:answ){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }

    cout<<"Recursion call...\n";
    vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve({1,2,3}, output, index, ans);
        for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }
    
    return 0;

}