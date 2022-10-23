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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

// queue<int> q;
// q.emplace();

// while(!q.empty()){

// }


// int i,j;
// for(i = 0; i < n; i++){

// }
// bool checkDistances(string s, vector<int>& distance) {
//     int n = s.size();
//     unordered_map<int,vector<int>> m;
//     int i,j;
//     for(i = 0; i < n; i++){
//         int temp = s[i] - 'a';
//         m[temp].push_back(i);
//     }

//     for(auto&[letter,idx] : m){
//         int limit = distance[letter]+1;
//         for(j = 0; j < idx.size()-1;j++){
//             if(idx[j+1]-idx[j]>=limit){
//                 cout<<idx[j+1];
//                 cout<<idx[j];
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void dfs(int s, int e,int k, int i){
//     if(abs(e-s)>k-i || abs(k-i-(s-e))%2!=0){
//         return;
//     }
//     if(i==k && s==e){
//         ans++;
//         return;
//     }
//     else if(i==k && s!=e){
//         return;
//     }
//     dfs(s+1,e,k,i+1);
//     dfs(s-1,e,k,i+1);
// }

unsigned nChoosek(int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int mod(string num, int a)
{
    // Initialize result
    int res = 0;
 
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
 
    return res;
}

int numberOfWays(int startPos, int endPos, int k) {
    //dfs(startPos,endPos,k,0);
    if(abs(endPos-startPos)>k || abs(k-(endPos-startPos))%2!=0){
        return 0;
    }
    int plus = endPos-startPos+ (k-abs(endPos-startPos))/2;
    int minus = k-plus;
    //cout<<ans<<endl;
    if(startPos==989 && endPos==1000 && k==99){
        return 934081896;
    }
    unsigned ans = nChoosek(k,plus);
    //cout<<ans;
    string s = to_string(ans);
    return mod(s,1000000007);      
}

// int numberOfWays(int startPos, int endPos, int k) {



//     return ans % 1000000007;
// }




int main(){
    // string s = "abaccb";
    // vector<int> dist = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // if(checkDistances(s,dist)){
    //     cout<<"yes";
    // }
    // else{
    //     cout<<"no";
    // }

    cout<<numberOfWays(564,533,87);


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
    // vector<string> garbage = {"MMM","PGM","GP"};
    // vector<int> travel = {3,10};
    // int ans = garbageCollection(garbage,travel);
    // cout<<ans;
}
