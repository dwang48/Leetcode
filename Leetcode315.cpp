#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<numeric>
#include<queue>
#include <string> 

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

using namespace std;




int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        FOR(0,n){
            string rev = to_string(nums[i]);
            reverse(rev.begin(),rev.end());
            int temp = stoi(rev);
            nums.push_back(temp);
        }
        FOR(0,nums.size()){
            s.insert(nums[i]);
        }
        return s.size();
    }

bool sumOfNumberAndReverse(int num) {
    FOR(0,num/2){
            string rev = to_string(i);
            //cout<<rev;
            reverse(rev.begin(),rev.end());
            int temp = stoi(rev);
            if(temp+i==num){
                cout<<temp<<endl;
                cout<<i<<endl;
                return true;
            }
        }
    return false;
}

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    vector<vector<int>> val(n,vector<int>(3));
    vector<int> f(n);
    int mi=-1,mx=-1,wrong=-1;
    vector<int> f(n);
    for(int i = 0; i < n;i++){
        if(nums[i]<minK||nums[i]>maxK){
            wrong = i;
        }
        else if(nums[i]==minK){
            mi = i;
        }
        if(nums[i]==maxK){
            mx = i;
        }
        val[i][0] = mi;
        val[i][1] = mx;
        val[i][2] = wrong;
    }
    if(nums[0]== minK && nums[0]==maxK){
        f[0] = 1;
    }
    for(int i = 1; i < n;i++){
        f[i] = f[i-1];
        if(minK>=nums[i]&& maxK<=maxK){
            f[i]+=max(min(val[i][0],val[i][1])-val[i][2],0);
        }
    }
    return f[n-1];
}






int main(){
    string rev = to_string(0);
            //cout<<rev;
            reverse(rev.begin(),rev.end());
            int temp = stoi(rev);
    cout<<temp;
    


}