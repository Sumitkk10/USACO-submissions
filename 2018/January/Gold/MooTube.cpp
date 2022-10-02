#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, q, component[N], total[N];
vector<pair<int, pair<int, int> > > edges;
pair<int, pair<int, int> > query[N];

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    if(a.F == b.F)
        return a.S.S < b.S.S;
    return a.F > b.F;
}

int find(int x){
    while(true){
        if(x == component[x])
            return x;
        component[x] = component[component[x]];
        x = component[x];
    }
}

void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v)
        return;
    total[v] += total[u];
    component[u] = v;
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        edges.pb({c, {u, v}});
    }

    for(int i = 1; i <= n; ++i){
        component[i] = i;
        total[i] = 1;
    }
    for(int i = 0; i < q; ++i){
        cin >> query[i].F >> query[i].S.F;
        query[i].S.S = i;
    }
    sort(edges.rbegin(), edges.rend());
    sort(query, query + q, cmp);
    vector<int> ans(q, 0);
    int j = 0;
    for(int i = 0; i < q; ++i){
        while(j < edges.size() and edges[j].F >= query[i].F){
            merge(edges[j].S.F, edges[j].S.S);
            ++j;
        }
        ans[query[i].S.S] = total[find(query[i].S.F)];
    }
    for(auto k : ans)
        cout << k - 1 << "\n";
}

int32_t main(){
    fast;
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
