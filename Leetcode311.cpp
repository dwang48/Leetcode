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




int longestContinuousSubstring(string s) {
      int n = s.size();
      int mx = 1;
      int i = 0;
      while(i<n-1){
        int temp = 1;
        while(s[i]-'a'+1==s[i+1]-'a'){
            temp++;
            mx = max(mx,temp);
            i++;
        }
        i++;
    }
    return mx;
}


vector<int> sumPrefixScores(vector<string>& words) {
    int n = words.size();
    vector<int> ans(n);
    unordered_map<string,int> m;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= words[i].size();j++){
            string temp = words[i].substr(0,j);
            if(m.find(temp)!=m.end()){
                m[temp]++;
            }
            else{
                m[temp] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        int scores = 0;
        for(int j = 1; j <= words[i].size();j++){
            scores+=m[words[i].substr(0,j)];
        }
        ans[i] = scores;
    }
    return ans;
}
vector<int> sumPrefixScores(vector<string>& words) {
    int n = words.size();
    vector<int> ans(n);
    unordered_map<string,int> m;
    int size = 0;
    for(int i = 0; i < n; i++){
        int temp =words[i].size();
        size = max(size,temp);
    }

    
}



int main(){
    //vector<int> = {}

    //cout<<;
    // string s = "abcdefghijklmnopqrstuvwxyz";
    // cout<<longestContinuousSubstring(s);
    vector<string> words = {"abc","ab","bc","b"};
    for(int i = 0;i < words.size();i++){
        cout<<sumPrefixScores(words[i]);
    }


}