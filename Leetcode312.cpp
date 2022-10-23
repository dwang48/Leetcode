#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<numeric>
#include<queue>

using namespace std;
unordered_map<int,int> m;
unordered_set<int> s;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    vector<string> ans;
    vector<pair<string,int>> vec;
    int i, j;
    for(i = 0; i < n;i++){
        vec.emplace_back(names[i],heights[i]);
    }

    sort(vec.begin(),vec.end(),[](const auto& v1, const auto& v2){
        return v1.second>v2.second;
    });

    for(i = 0; i < n; i++){
        ans.push_back(vec[i].first);
    }

    return ans;
}




vector<int> goodIndices(vector<int>& nums, int k) {
    int i = k;
    int n = nums.size();
    int j = 0;
    vector<int> ans;
    while(i < n-k){
        bool flag = true;
        for(j = i-k; j < i; j++){
            if(nums[j]>=nums[j+1]){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag){
        for(j = i; j < i+k-1; j++){
            if(nums[j]<=nums[j+1]){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        }
        if(flag){
            ans.push_back(i);
        }
        i++;
    }
    return ans;
}




int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> presum(n);
    vector<int> suffsum(n)
    presum[0] = nums[0];

    for(int i = 1; i < n+1;i++){
        presum[i] = presum[i-1]&nums[i-1];
    }   



}




int main(){
    vector<int> nums = {2,1,1,1,3,4,1};
    int k = 2;
    goodIndices(nums)
}