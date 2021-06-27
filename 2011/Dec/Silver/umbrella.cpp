#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
long long int n, m, a[N], cost[N];

void solve(){
    cin >> n >> m;
    long long dp[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i] = 1e13;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= m; ++i)
        cin >> cost[i];
    long long suf_min[m + 2];
    suf_min[m + 1] = INT_MAX;
    for(int i = m; i >= 1; --i)
        suf_min[i] = min(suf_min[i + 1], cost[i]);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        long long int mn = 1e13;
        for(int j = i - 1; j >= 0; --j){
            long long cur = suf_min[a[i] - a[j + 1] + 1];
            mn = min(mn, cur + dp[j]);
        }
        dp[i] = mn;
    }
    cout << dp[n] << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
