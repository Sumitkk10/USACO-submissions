#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
map<int, int> deg;
int n, ans;

void solve(){
    cin >> n;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        ans = max({ans, deg[u], deg[v]});
    }
    cout << ans + 1 << '\n';
}

int main(){
    fast;
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
