#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, pair<int, int> > > graph[N];
ll n, m, x, dis[N];

void dijkstra(int node){
    dis[node] = 0;
    priority_queue<pair<int, pair<int, pair<int, int> > >, vector<pair<int, pair<int, pair<int, int> > > >, greater<pair<int, pair<int, pair<int, int> > > > > pq;
    pq.push({0, {0, {INT_MAX, node}}});
    while(!pq.empty()){
        int cost = pq.top().F;
        int sum = pq.top().S.F, minimum = pq.top().S.S.F, cur_node = pq.top().S.S.S;
        pq.pop();
        // cout << sum << ' ' << cur_node << "\n";
        for(auto k : graph[cur_node]){
            ll cur = sum + k.S.F, mini = min(minimum, k.S.S);
            if(dis[k.F] > cur + x/mini){
                dis[k.F] = cur + x/mini;
                pq.push({dis[k.F], {cur, {mini, k.F}}});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> x;
    for(int i = 1; i <= m; ++i){
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        graph[u].push_back({v, {l, c}});
        graph[v].push_back({u, {l, c}});
    }
    for(int i = 1; i <= n; ++i)
        dis[i] = INT_MAX;
    dijkstra(1);
    cout << dis[n] << "\n";
}

int main(){
    fast;
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
