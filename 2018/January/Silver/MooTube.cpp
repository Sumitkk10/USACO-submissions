#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 5000 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, long long int> > graph[N];
bool vis[N];

int main() {
    fast;
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        long long int r;
        cin >> u >> v >> r;
        graph[u].push_back({v, r});
        graph[v].push_back({u, r});
    }
    while(q--){
        for(int i = 1; i <= n; ++i)
            vis[i] = false;
        long long int k, node;
        cin >> k >> node;
        queue<pair<long long int, int> > q; // dis -- node;
        q.push({LLONG_MAX / 100, node});
        int ans = -1;
        while(!q.empty()){
            int cur_node = q.front().second;
            long long mn = q.front().first;
            q.pop();
            if(cur_node != node)
                if(mn < k)
                    continue;
            vis[cur_node] = true;
            ++ans;
            for(auto k : graph[cur_node])
                if(!vis[k.first]) {
                    q.push({min(mn, k.second), k.first});
                    vis[k.first] = true;
                }
        }
        cout << ans << '\n';
    }
    return 0;
}
