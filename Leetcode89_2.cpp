#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<numeric>
#include<queue>
#include<math>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef long long ll;
#define FOR(a,b) for(int i=a;i<b;++i)
#define NFOR(a,b) for(int i=a;i>=b;--i)
#define FORJ(a,b) for(int j=a;j<b;++j)
#define NFORJ(a,b) for(int j=a;j>=b;--j)
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1e9+7

int countTime(string time) {
    int n = time.size();
    int ans = 1;
    int flag = false;
    if(time[0]=='?'){
        if(time[1]>=4){
            ans*=2;
        }
        else{
            ans*=3;
        }
    }
    if(time[1]=='?'){
        if(time[0]==2){
            ans*=4;
        }
        else if(time[0]=='?'){
            ans*=8;
        }
        else{
            ans*=10;
        }
    }  
    if(time[3]=='?'){
        ans*=6;
    }
    if(time[4]=='?'){
        ans*=10;
    }
    if(ans==1){
        return 0;
    }
}



vector<int> productQueries(int n, vector<vector<int>>& queries) {
    int size = queries.size();
    vector<int> powers;
    vector<int> ans;

    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        powers.push_back(pow(2,i));
      }
    }
    FOR(0,powers.size()){
        cout<<powers[i];
    }

    int presum[powers.size()+1];
    presum[0] = 1;
    FOR(1,powers.size()){
        presum = presum[i-1]*powers[i];
    }
    FOR(0,size){
        ans.push_back(presum[queries[i][1]]/(queries[i][0]-1));
    }
    return ans;
}

int minimizeArrayValue(vector<int>& nums) {
    int n = nums.size();

}

int main(){

}