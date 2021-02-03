#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 2;
vector<pair<int, long long int> > graph[N];
long long n, m, c, a[N], in[N];

void solve() {
    cin >> n >> m >> c;
    vector<long long int> ans(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans[i] = a[i];
    }
    for(int i = 1; i <= c; ++i){
        long long int u, v, cc;
        cin >> u >> v >> cc;
        graph[u].push_back({v, cc});
        in[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
            ans[i] = a[i];
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto k : graph[node]){
            ans[k.first] = max(ans[k.first],ans[node] + k.second);
            in[k.first]--;
            if(in[k.first] == 0)
                q.push(k.first);
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";
}

int main() {
    fast;
    int t = 1;
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    while(t--)
        solve();
    return 0;
}
