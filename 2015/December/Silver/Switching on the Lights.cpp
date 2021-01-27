#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100 + 5;
const int MOD = 1e9 + 7;
map<pair<int, int>, vector<pair<int, int> > > lights;
int n, m, ans = 1;
bool vis[N][N], a[N][N];

void dfs(int i, int j){
    if(i <= 0 or j <= 0 or i > n or j > n or vis[i][j] or !a[i][j])
        return;
    for(auto k : lights[{i, j}]) {
        if(!a[k.first][k.second]){
            a[k.first][k.second] = true;
            ans++;
            if(vis[k.first + 1][k.second]) dfs(k.first, k.second);
            if(vis[k.first - 1][k.second]) dfs(k.first, k.second);
            if(vis[k.first][k.second + 1]) dfs(k.first, k.second);
            if(vis[k.first][k.second - 1]) dfs(k.first, k.second);
        }
    }
    vis[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    fast;
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        lights[{x, y}].push_back({a, b});
    }
    a[1][1] = true;
    dfs(1, 1);
    cout << ans << '\n';
    return 0;
}
