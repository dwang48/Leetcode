#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<numeric>





using namespace std;



vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int total = accumulate(nums.begin(),nums.end(),0);
    int n = nums.size();
    int q = queries.size();
    int i,j;
    vector<int> ans(q);
    sort(nums.begin(),nums.end(),greater<int>());

    for(i = 0; i < q; i++){
        int count = n;
        int temp = queries[i];
        int to = total;
        for(j = 0; j < n; j++){
            if(temp < to){
                to -= nums[j];
                count--;
            }
            else{
                ans[i] = count;
                break;
            }
        }
    }
    return ans;
}

string removeStars(string s) {
    int n = s.size();
    stack<char> stk;
    stack<char> stk2;
    int i = 0;
    int count = 0;
    while(i < n){
        if(s[i] != '*' && count==0){
            stk.push(s[i]);
            i++;
        }
        else if(s[i] !='*' && count!=0){
            stk.pop();
            count--;
        }
        else if(s[i]=='*'){
            count++;
            i++;
        }
    }
    while(count!=0){
        stk.pop();
        count--;
    }


    string ans = "";
    while(!stk.empty()){
        stk2.push(stk.top());
        stk.pop();
    }
    while(!stk2.empty()){
        ans.push_back(stk2.top());
        stk2.pop();
    }

    return ans;

}



vector<int> f;  
int sumRange(int left, int right) {
    // cout<<f[right];
    // cout<<f[left];
    return f[right+1]-f[left];
}

int garbageCollection(vector<string>& garbage, vector<int>& travel){
        int minutes = 0;
        int n = garbage.size();
        int i,j;
        int G = 0,P = 0,M = 0;
        int endG = 0, endP = 0, endM = 0;
        for(i = 0; i < n; i++){
            int len = garbage[i].size();
            for(j = 0; j < len;j++){
                if(garbage[i][j] == 'G'){
                    G++;
                    endG = i;
                }
                else if(garbage[i][j] == 'M'){
                    M++;
                    endM = i;
                }
                else{
                    P++;
                    endP = i;
                }
            }
        }
        minutes = G+P+M;
        f.resize(travel.size()+1);
        f[0] = 0;
        for(int i = 1; i < travel.size();i++){
            f[i] = f[i-1]+travel[i-1];
        }
        minutes+= accumulate(travel.begin(),travel.begin()+endG,0);
        minutes+= accumulate(travel.begin(),travel.begin()+endP,0);
        minutes+= accumulate(travel.begin(),travel.begin()+endM,0);
        cout<<endP<<endl;
        return minutes;
}



int main(){
    // int target;
    // vector<int> nums;
    // vector<int> queries;

    // nums = {2,3,4,5};
    // queries ={1};




    // vector<int> ans = answerQueries(nums,queries);
    // for(int i = 0; i < ans.size();i++){
    //     cout<<ans[i]<<endl;
    // }

    // string s = "erase*****";
    // string after = removeStars(s);

    // cout<<after;
    
    
    
    vector<string> garbage = {"MMM","PGM","GP"};
    vector<int> travel = {3,10};
    int ans = garbageCollection(garbage,travel);
    cout<<ans;
}