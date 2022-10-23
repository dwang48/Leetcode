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

// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};
// int numEnclaves(vector<vector<int>>& grid) {
//     int m =grid.size(), n = grid[0].size();
//     vector<vector<int>> visited(m,vector<int>(n,0));     
//     queue<pair<int,int>> q;
//     int i,j;
//     for(i = 0; i < m; i++){
//         for(j = 0; j < n;j++){
//             if(grid[i][j]==1&&(i==0||j==0||i==m-1||j == n-1)){
//                 q.emplace(i,j);
//                 visited[i][j]++;
//             }
//         }
//     }

//     while(!q.empty()){
//         auto [x,y] = q.front();
//         q.pop();
//         for(i = 0; i < 4; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//         if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==1&&!visited[nx][ny]){
//             q.emplace(nx,ny);
//             visited[nx][ny] = 1;
//         }   
//         }
//     }

//     int ans = 0;
//     for(i = 0; i < m ; i++){
//         for(j = 0; j < n; j++){
//             if(visited[i][j]==0 && grid[i][j] == 1){
//                 ans++;
//             }
//         }
//     }

//     //cout<<AO[0][0]<<PO[0][0];

//     return ans;

// }

// int start = 0, end = n;
// while(start+1<end){
//     int mid = start+(end-start)/2;
    
// }

// if([end]==){

// }
// if([start]==){

// }

int mostFrequentEven(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> m;
    for(int i = 0; i < n; i++){
        if(nums[i]%2==0){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
            }
            else{
                m[nums[i]] = 1;
            }
        }
    }

    int mx = -1;
    int mxc = 0;
    for(auto& count:m){
        if(count.second > mxc){
            mx = count.first;
            mxc = count.second;
        }
        else if(count.second==mxc && count.first<mx){
            mx = count.first;
            mxc = count.second;
        }
    }
    return mx;        
}

// void dfs(string s, int idx){

// }

int partitionString(string s) {
    int n = s.size();
    unordered_set<char> set;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(set.find(s[i])!=set.end()){
            count++;
            set.clear();
            set.insert(s[i]);
        }
        else{
            set.insert(s[i]);
        }
    }
    if(!set.empty()){
        count++;
    }
    return count;
}

int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    priority_queue<int,vector<int>, greater<int>> heap;
    int n = intervals.size();
    heap.push(intervals[0][1]);
    for(int i =1;i < n; i++){
        int t = heap.top();
        heap.pop();
        if(t < intervals[i][0]){
            t = intervals[i][1];
        }
        else{
            heap.push(intervals[i][1]);
        }
        heap.push(t);
    }
    return heap.size();
}


int lengthOfLIS(vector<int>& nums, int k) {
       int n = nums.size();
       int ans = 0;

        vector<int> f(n,1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i]-nums[j]<=k && nums[i]>nums[j]){
                    f[i] = max(f[i],f[j]+1);
                }
            }
        }
        return *max_element(f.begin(),f.end()); 
}
    //  int lengthOfLIS(vector<int>& nums, int k) {
    //     int len = 1, n = (int)nums.size();
    //     if (n == 0) {
    //         return 0;
    //     }
    //     vector<int> d(n + 1, 0);
    //     d[len] = nums[0];
    //     for (int i = 1; i < n; ++i) {
    //         if (nums[i] > d[len] && nums[i]-d[len]<=k) {
    //             d[++len] = nums[i];
    //         } else {
    //             int l = 1, r = len, pos = 0;
    //             while (l <= r) {
    //                 int mid = (l + r) >> 1;
    //                 if (d[mid] < nums[i] && nums[i]-d[mid]<=k) {
    //                     pos = mid;
    //                     l = mid + 1;
    //                 } else {
    //                     r = mid - 1;
    //                 }
    //             }
    //             d[pos + 1] = nums[i];
    //         }
    //     }
    //     return len;
    // }

    int lengthOfLIS(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 1;
        for(int i = 0 ; i < arr.size() ; i++){
            int prevApElement = arr[i] - difference;
            dp[arr[i]] = 1 + dp[prevApElement];
            ans = max(dp[arr[i]], ans);
        }
        return ans;
    }


// }




int main(){
    //vector<int> nums = {29,47,21,41,13,37,25,7};
    //cout<<mostFrequentEven(nums);

    // vector<int> = {};
    // string s = "abacaba";
    // cout<<partitionString(s);

    // vector<vector<int>> intervals = {{5,10},{6,8},{1,5},{2,3},{1,10}};
    // cout<<minGroups(intervals);

    vector<int> nums = {4,2,1,4,3,4,5,8,15};
    int k = 3;
    cout<<lengthOfLIS(nums,k);

}