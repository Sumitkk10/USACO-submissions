#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
int n;
vector<bool> vis(N);

void dfs(int node){
    vis[node] = 1; 
    for(auto k : graph[node]){
        if(!vis[k])
            dfs(k);
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
    }
    vis.resize(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            vis[j] = 0;
        dfs(i);
        bool ok = 0;
        for(int j = 1; j <= n; ++j)
            if(!vis[j])
                ok = 1;
        if(!ok){
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main(){
    fast;
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
