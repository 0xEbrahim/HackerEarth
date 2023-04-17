#include <bits/stdc++.h>
using namespace std;

const int MAXN =1e5+7;
bool vis[MAXN];
vector<int>adj[MAXN];
void dfs(int node){
    vis[node] = 1;
    for(auto ch : adj[node]){
        if(!vis[ch]){
            dfs(ch);
        }
    }
}

int countComp(int numberOfNodes){
    int cnt = 0;
    for(int i = 1 ; i <= numberOfNodes ; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

int main(){
int n,m;
cin>>n>>m;
for(int i = 0 ; i < m ; i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int count = countComp(n);
cout<<count;
}
