#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, long long> > graph[N];
int n, m, a[N], connected[N];
bool vis[N];

void dfs(int source, int colour, long long int mx){
    vis[source] = 1;
    connected[source] = colour;
    for(auto k : graph[source])
        if(!vis[k.first] and k.second >= mx)
            dfs(k.first, colour, mx);
}

bool possible(long long mx){
    for(int i = 1; i <= n; ++i) {
        connected[i] = -1;
        vis[i] = false;
    }
    int col = 0;
    for(int i = 1; i <= n; ++i){
        if(connected[i] != -1)
            continue;
        dfs(i, ++col, mx);
    }
    for(int i = 1; i <= n; ++i)
        if(connected[i] != connected[a[i]] or connected[i] == -1)
            return false;
    return true;
}

int main() {
    fast;
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    long long low = 0, high = 1e12, ans = -1;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        if(possible(mid)){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << (ans == 1e12 ? -1 : ans) << '\n';
    return 0;
}
/*
4 4
3 2 1 4
1 2 9
1 3 7
2 3 10
2 4 3
 */
