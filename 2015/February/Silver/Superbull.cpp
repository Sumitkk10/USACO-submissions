#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N], component[N];
vector<pair<ll, pair<int, int> > > edges;

int find(int x){
    while(true){
        if(x == component[x])
            return x;
        component[x] = component[component[x]];
        x = component[x];
    }
}

void merge(int a, int b){
    int u = find(a), v = find(b);
    component[u] = v;
}

ll MST(){
    ll ans = 0;
    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].second.first, v = edges[i].second.second;
        if(find(u) == find(v)) continue;
        ans += edges[i].first;
        merge(u, v);
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        component[i] = i;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            edges.push_back({a[i] ^ a[j], {i, j}});
    sort(edges.rbegin(), edges.rend());
    cout << MST() << "\n";
}

int main(){
    fast;
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
