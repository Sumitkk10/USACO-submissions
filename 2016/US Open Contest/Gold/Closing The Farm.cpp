#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> out[N];
long long n, q[N], components[N], m;

int find(int x){
    while(true){
        if(x == components[x])
            return x;
        components[x] = components[components[x]];
        x = components[x];
    }
}

void merge(int a, int b){
    int u = find(a), v = find(b);
    components[u] = v;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        out[u].push_back(v);
        out[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        cin >> q[i];
        components[i] = i;
    }
    vector<string> ans;
    ll mx = 0;
    vector<bool> vis(n + 1, 0);
    int comp = 0;
    for(int i = n; i >= 1; --i){
        int x = q[i];
        bool ok = 0, okk = 0;
        set<int> s;
        for(auto k : out[x]){
            if(!vis[k])
                ok = 1;
            else{
                okk = 1;
                s.insert(find(k));
            }
        }
        if(!okk)
            ++comp;
        if(s.size() > 1)
            comp = comp - s.size() + 1;
        if(comp == 1) ans.push_back("YES");
        else ans.push_back("NO");
        for(auto k : out[x])
            if(vis[k])
                merge(k, x);
        vis[x] = true;
    }
    reverse(ans.begin(), ans.end());
    for(auto k : ans)
        cout << k << '\n';
}

int main(){
    fast;
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
