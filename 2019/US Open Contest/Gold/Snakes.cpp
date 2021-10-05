#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k, a[N];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    long long dp[n + 1][k + 1];
    int range_max[n + 1][n + 1], pre_sum[n + 1];
    // dp[i][k] --> the min ans of prefix i with exactly k flips;
    for(int i = 0; i <= k; ++i){
        dp[1][i] = 0;
        dp[0][i] = 0;
    }
    pre_sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        range_max[i][i] = a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i]; 
        for(int j = i + 1; j <= n; ++j)
            range_max[i][j] = max(range_max[i][j - 1], a[j]);
    }
    ll ans = INT_MAX;
    int mxx = a[1];
    for(int i = 2; i <= n; ++i){
        int cur = 0;
        mxx = max(mxx, a[i]);
        for(int j = 1; j <= i; ++j)
            cur += mxx - a[j];
        dp[i][0] = cur;
        for(int flips = 1; flips <= k; ++flips){
            dp[i][flips] = INT_MAX;
            for(int j = i; j >= 1; --j){
                int mx = range_max[j][i];
                int res = mx*(i - j + 1) - pre_sum[i] + pre_sum[j - 1];
                dp[i][flips] = min(dp[i][flips], dp[j - 1][flips - 1] + res);
            }
            if(i == n)
                ans = min(ans, dp[i][flips]);
        }
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    while(t--)
        solve();
    return 0;
}
