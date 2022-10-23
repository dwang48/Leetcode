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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007


int hardestWorker(int n, vector<vector<int>>& logs) {
    int size = logs.size();
    int mx = logs[0][1], id = logs[0][0];
    for(int i = 1; i < size ; i++){
        if(logs[i][1]-logs[i][0]>mx){
            mx = logs[i][1]-logs[i][0];
            id = logs[i][0];
        }
        else if(logs[i][1]-logs[i][0]==mx && logs[i][0]<id){
            id = logs[i][0];
        }
    }
    return id;
}

vector<int> findArray(vector<int>& pref) {
    int n = pref.size();
    vector<int> arr(n);
    arr[0] = pref[0];
    for(int i = 1; i < n ; i++){
        arr[i] = arr[i-1]^pref[i];
    }
    return arr;
}

// string robotWithString(string s) {
    
// }


int main(){
    int x = 5^7^7;
    cout<<x;

}